(ns day1 (:require [clojure.java.io :as io]))

(defn get-lines []
  (let [f (io/file "input1")]
    (.split (slurp f) "\n\n")))

;; There's probably a better way to do this -- using the static method directly in the map failed (probably due to not being able to guess the first operand?)
(defn to-int [^String s]
  (java.lang.Integer/parseUnsignedInt s))

(def sorted-results
  (reverse (sort
  (for [line (get-lines)]
    (reduce + (map to-int (.split line "\n")))))))

(first sorted-results) ;; 68292
(reduce + (take 3 sorted-results)) ;; 203203
