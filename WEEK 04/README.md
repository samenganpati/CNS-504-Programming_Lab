In this week , we have to do compare dfs / bfs using my own stack / queue with general dfs / bfs .


This week the aim is to learn further program analysis using graph algorithms in particular using gnuplot.
We have a different problem statement this week.

Problem: Write a single code to compute BFS (or DFS) forests of a graph by using Queues (or Stacks).
                Additionally, write a code for computing DFS using recursion.
                Plot (using GnuPlot) the variation of their average performance (average over several test cases) on random graphs under following settings:
                1- VarM: Fixed N (nodes, say 200,500,1000) and variable M(edges) varying from 2n to nC2 computed randomly.
                2- VarN: Fixed Sparsity (say m= 2n, nlog n, n\sqrt{n}, nC2) and variable N (nodes) varying from 100,200,...,1000

Procedure:               
1- Make your testing framework modular so that easily one can change the required algorithms for testing a particular kind of input.
    Eg. Random graphs under above variations for different algorithms.
2- Same code for BFS/DFS by defining compile time variable say "-D BFS" for BFS and default for DFS.
     Another code for recurive DFS using the same testing framework.
     Tools/concepts used: Makefile along with Compile time and Runtime Parameters,
                                           Random input generation which is reproducible using random seed.
                                           Take average over several test cases to report performance.
3- Plot the above results total time or Space using GnuPlot.
     Tools/concepts used: Output and store time and space using /usr/bin/time by using error stream
                                            Use bash scripting to collect and summarize data from files.
                                           Write GnuPlot Script for plotting with appropriate x and y axis parameters.


The output should be following plots for the three algorithms together:
          1- Different plots of VarM for different values of N (200,500,1000)
          2- Different plots of VarN for different sparsities of M (2n,nlog n, n\sqrt{n}, nC2)