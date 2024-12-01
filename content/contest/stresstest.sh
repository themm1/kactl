# Runs n (input argument) stress tests and stops on first wrong answer.
g++ -O2 program.cpp -o exe_your
g++ -O2 solution.cpp -o exe_sol
n=$1
for (( i=1; i<=n; ++i )) do
    python3 generator.py > input.txt

    ./exe_your < input.txt > out_your.txt
    ./exe_sol < input.txt > out_sol.txt
    MESSAGE=$(diff out_sol.txt out_your.txt)
    if [[ $MESSAGE != "" ]]; then
        echo
        echo $MESSAGE
        echo "WA on test $i"
        echo
        break
    else
        echo "AC on test $i"
    fi
done

