(ns day2 (:require [clojure.java.io :as io]
                   [clojure.core.match :as match]))

(defn get-move [move]
  (case move
    "A" :rock
    "B" :paper
    "C" :scissors
    "X" :rock
    "Y" :paper
    "Z" :scissors))

(defn get-value [move]
  (case move
    :rock 1
    :paper 2
    :scissors 3))

(defn get-moves []
  (let [lines
        (let [f (io/file "input2")]
          (.split (slurp f) "\n"))
        moveo (fn [a] [(get-move (last a)) (get-move (first a))])]
    (map #(moveo (.split % " ")) lines)))

(defn score-round [round]
  (+ (get-value (first round))
     (match/match [round]
       [[:rock :rock]] 3
       [[:paper :paper]] 3
       [[:scissors :scissors]] 3
       [[:rock :scissors]] 6
       [[:paper :rock]] 6
       [[:scissors :paper]] 6
       [[_ _]] 0)))

(reduce + (map score-round (get-moves))) ;; 12156
