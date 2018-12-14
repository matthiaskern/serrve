# serrve
Static file server written in ReasonML.

## Installation
```
npm install -g serrve
```

## Manual
```
serrve(1)                        Serrve Manual                       serrve(1)



NAME
       serrve - Serve static files.

SYNOPSIS
       serrve [OPTION]... [PATH]

ARGUMENTS
       PATH (absent PATH env)
           The path to serve.

OPTIONS
       --help[=FMT] (default=auto)
           Show this help in format FMT. The value FMT must be one of `auto',
           `pager', `groff' or `plain'. With `auto', the format is `pager` or
           `plain' whenever the TERM env var is `dumb' or undefined.

       -p NUMBER, --port=NUMBER (absent=3000)
           Port for development server to listen on

       --version
           Show version information.

EXIT STATUS
       serrve exits with the following status:

       0   on success.

       124 on command line parsing errors.

       125 on unexpected internal errors (bugs).

ENVIRONMENT
       These environment variables affect the execution of serrve:

       PATH
           The path to serve.

BUGS
       Email bug reports to <matthias_kern at posteo.net>.
```
