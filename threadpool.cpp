/*

.

🔹 Idea of a Thread Pool

You start a fixed number of worker threads (say 4).

These threads sit in a loop, waiting for jobs.

When a client thread gets a request (a line), it:

Parses it.

Creates a job object (function/task).

Pushes it into a job queue.

Waits for the result (future/promise).

One of the worker threads wakes up, takes the job, runs it, produces the result, signals back.

Client thread takes the result and sends it back over the socket.

This way:

Client threads stay lightweight → just parsing + enqueuing.

Heavy filesystem logic runs in a controlled pool of workers.

CPU is used efficiently, avoids too many OS threads.
*/