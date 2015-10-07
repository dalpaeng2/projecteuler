(ns clj.core
  (:gen-class))

(defn palindrom?
  [number]
  (.equals (str number) (clojure.string/join (reverse (str number)))))



(defn -main
  [& args]
  (println (apply max (filter palindrom? (for [x (range 100 1000) y (range 100 1000)] (* x y))))))
