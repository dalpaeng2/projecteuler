(ns clj.core
  (:gen-class))

(defn solve
  []
 (reduce + (filter #(or (= (mod % 3) 0) (= (mod % 5) 0)) (range 1 1000))))

(defn -main
  [& args]
  (println "answer:" (solve)))
