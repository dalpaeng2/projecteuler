#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <unistd.h>
// 18407904

const int limit = 120000;
// const int limit = 1000;
int sum_c = 0;

std::map<int ,std::set<int> > s;
std::vector<int> primes;

struct triplet {
	int a;
	int b;
	int c;
	triplet(int _a, int _b, int _c): a(_a), b(_b), c(_c) { }
};

class Queue
{
public:
	triplet pop()
	{
		std::unique_lock<std::mutex> mlock(mutex_);
		while (queue_.empty())
		{
			cond_.wait(mlock);
		}
		auto item = queue_.front();
		queue_.pop();
		return item;
	}

	void push(triplet item)
	{
		std::unique_lock<std::mutex> mlock(mutex_);
		queue_.push(item);
		mlock.unlock();
		cond_.notify_one();
	}

	bool empty()
	{
		return queue_.empty();
	}

	std::size_t size()
	{
		return queue_.size();
	}

private:
	std::queue<triplet> queue_;
	std::mutex mutex_;
	std::condition_variable cond_;
};

Queue g_queue;

std::mutex g_sum_mutex;

int64_t gcd(int64_t a, int64_t b)
{
	return b == 0 ? a : gcd(b, a % b);
}

bool is_prime(const int n)
{
	if (n <= 1)
		return false;
	else if (n <= 3)
		return true;
	else if (n % 2 == 0 || n % 3 == 0)
		return false;

	int i = 5;
	while (i * i <= n)
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
		i += 6;
	}

	return true;
}

void get_primes(std::vector<int>& p, int l)
{
	p.push_back(2);
	for (auto i = 3; i < l; i+=2)
	{
		if (is_prime(i))
			p.push_back(i);
	}
}

std::set<int> prime_factors(int n)
{
	std::set<int> factors;

	for (std::vector<int>::iterator it = primes.begin(); it != primes.end(); it++)
	{
		int i = *it;
		if (i > n) 
			break;
		if (n % i == 0)
			factors.insert(i);
	}

	return factors;
}

int64_t rad(int a, int b, int c)
{
	std::set<int> t;
	t.insert(s[a].begin(), s[a].end());
	t.insert(s[b].begin(), s[b].end());
	t.insert(s[c].begin(), s[c].end());

	return std::accumulate(t.begin(), t.end(), 1LL, std::multiplies<int64_t>());
}

void func(int m, int n)
{
	auto a = n;
	auto b = m;
	auto c = m + n;

	if (c >= limit)
		return;

	// enqueue;
	g_queue.push(triplet(a, b, c));
	
	func(2*m - n, m);
	func(2*m + n, m);
	func(m + 2*n, n);
}

void thread_function()
{
	while (true)
	{
		triplet t = g_queue.pop();

		if (gcd(t.a, t.c) == 1 && gcd(t.b, t.c) == 1 && rad(t.a, t.b, t.c) < t.c)
		{
			std::unique_lock<std::mutex> sum_guard(g_sum_mutex);
			sum_c += t.c;
			std::cout << "(" << t.a << ", " << t.b << ", " << t.c << ")\n"
				<< sum_c << "\n";
		}
	}
}

int main(void)
{
	get_primes(primes, limit);
	s[1] = std::set<int>{1};
	for (int i = 2; i < limit; i++)
	{
		s[i] = prime_factors(i);
	}

	std::thread th1(thread_function);
	std::thread th2(thread_function);
	std::thread th3(thread_function);
	std::thread th4(thread_function);
	std::thread th5(thread_function);
	std::thread th6(thread_function);
	std::thread th7(thread_function);
	std::thread th8(thread_function);

	func(2, 1);
	func(3, 1);

	while (!g_queue.empty())
	{
		sleep(1);
	}

	th1.detach();
	th2.detach();
	th3.detach();
	th4.detach();
	th5.detach();
	th6.detach();
	th7.detach();
	th8.detach();

	std::cout << "answer: " << sum_c << "\n";
	
	return 0;
}


