Joshua Thompson
11/20/2022

This project aims to implement the bankers algorithm.  Included in this implementation
is five processes and three unique resources.  Resources are limited, and each process
have a maximum amount of a resource they can allocate.  This implementation is coded
in C++.

Compared to my last project, I decided to put this all in a single file, separating
the file by sections using comments. 

I believe there is a flaw in this project.  Unfortunately I no longer have the time to
correct this error, but I shall leave the details here.  All the resources available,
resources allocated, and resources available were given in a table:

![image](https://user-images.githubusercontent.com/117226386/202966229-42c1f53a-fdb4-4127-8867-c36a9839a29b.png)

I translated the table into several vectors and matrices in order to solve this problem.
However, when I attempted to find a safe sequence, I ended up finding none:

![image](https://user-images.githubusercontent.com/117226386/202966822-1bf20559-1dcb-4baa-9cf4-1759ad69c9c2.png)


This does not make sense to me because it seems that by the table, there should be enough
resources available for at least one possible safe sequence to be made.  One other major
issue I had with this project was using matrices.  I have only used matrices once before
and it was minimal use, so using matrices a lot in this project was tough.
