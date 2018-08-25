#!/bin/bash

readonly RED='\033[0;31m'
readonly NC='\033[0m'  # No Color

#clear

g++ -Wall main.cpp -o program.out && ./program.out
exit

g++ -Wall main.cpp -o program.out

declare -a collection=(
  "The sound sounds sound."
  "It's the right right, right?"
  "The key key is this one."
  "It's an objective objective."
  "In May, May may make out with me."
  "A can can help."
  "Compared with the last one, this is a fine fine."
  "Fat fat."
  "The man we saw saw a saw."
  "The first second was alright, but the second second was tough."
  "It's a square square. It's a flat flat."
  "Well, well, well... There there. lol lol lol"
)

cnt=0
if [ -n "$collection" ]; then
    for i in "${collection[@]}"
    do
      echo -e "${RED}Test # $cnt${NC}"
      echo "$i" | ./program.out
      let cnt=cnt+1
    done
fi
