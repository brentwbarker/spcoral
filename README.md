coral
=====

To Compile
----------

First edit the directories in `makefile_defs.mk`.


If needed, compile and install coral:
    $ cd rhic/coral ; make all ; make install

To Run
------

You can edit the source function file in `run/brent.cc`.

Navigate to `run/`, and execute `make`.

Then you can run the code by running `run/brent`. The correlation function is printed to stdout.

Note that the first bin of the correlation function is unphysical, can be ignored, and should be manually deleted or commented out.
