(ns clj.core
  (:gen-class))

(def fibonacci
  ((fn rfib [a b]
    (lazy-seq (cons a (rfib b (+ a b)))))
   1 2))

(defn solve
  []
  (reduce + (filter even? (take-while #(< % 4000000) fibonacci))))


(defn -main
  [& args]
  (println "answer:" (solve)))
