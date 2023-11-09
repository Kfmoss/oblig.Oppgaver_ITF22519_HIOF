

function read_file {
  echo "insert a word, please: "
  read test
  num=0
  while read -ra line;
  do
    for word in "${line[@]}";
    do
      # echo "$word"
      if [ "$word" == "$test" ]
      then
        ((num++));
      fi
    done;
  done < oppgave_1.sh
  echo "match: $num"

}

read_file

