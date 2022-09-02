# Communication via files
Pair of programs (client - server) communicating each other using text files.
Server program waits for the data to be written to the file by client program, 
processes it and saves the result to the results file. Client reads the processed data, 
prints it and ends work. **Server works contiunously waitng for the clients.**

Client enters a signle integer using standard input, whereas server computes simple arthmetic function $x^3$.

## remarks
* run programs in separate terminals
* add _-lm_ when compiling server program
* run server program first
