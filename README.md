comparing speeds of `eigen` and `numpy` at doing matrix operations 🤓

to install eigen and numpy:

    bash setup.sh

to run the benchmark:

    bash benchmark.sh <num_rows_of_matrix> <num_cols_of_matrix> <num_iters>

results(on 500x500 matrices and 100 iterations):

    ---------------------------------------
    eigen results:

    op: +
    time taken: 0.0059604 secs

    op: *
    time taken: 7.2502171 secs

    op: -
    time taken: 0.0166421 secs

    op: /
    time taken: 0.0194903 secs

    op: .
    time taken: 6.6296824 secs

    ---------------------------------------

    ---------------------------------------
    numpy results:

    op: +
    time taken: 0.0016540 secs

    op: *
    time taken: 0.0015308 secs

    op: -
    time taken: 0.0013248 secs

    op: /
    time taken: 0.0013072 secs

    op: .
    time taken: 0.0045960 secs

    ---------------------------------------
