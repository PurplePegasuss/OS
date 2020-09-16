if test ! -f numbers.txt
then  
    echo 0 > numbers.txt
fi

if ln numbers.txt numbers.txt.lock
    then 
    for ((i=1; i < 40; i++)) 
    do
        n=$(tail -1 < numbers.txt)
        expr $n + 1 >> numbers.txt 
    done
    rm numbers.txt.lock
fi


<< 'COMMENT_SECTION'
    How long does it take before a race condition manifests itself?:

    The race condition happens straight then 2 different instances (in our case - from the foreground and from the background)
    try to access the same file (in our case - numbers.txt) at the same time. We can avoid race conditions with busy waiting, 
    semaphores, monitors etc. It's hard to approximate when it hapens exactly, as it depends on the OS structure and hardware,
    however on my device it crashed barely on the 1st - 2nd iteration.  

    What is the critical region?:

    A section of memory that is reserved by a separate instance during execution. If another instance tries to access this 
    memory section, the instance is blocked until the first instance finishes working.
COMMENT_SECTION