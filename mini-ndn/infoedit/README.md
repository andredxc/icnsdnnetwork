A tool used to edit NFD configuration files
===========================================

This tool is majorly developed for use in NFD integration tests.  However, it can also used to
edit any INFO-formatted files.

Each invocation of `infoedit` tool performs exactly one edit and the file is modified in place.
To perform multiple edits, `infoedit` tool should be invoked multiple times on the same file.

## Usage ##

    infoedit [-f file] [-s|d|a|r path] [-v value]

OPTIONS:

* `-f file`: specifies a file to edit
* `-s path`: specifies a property-tree path to modify
* `-p path`: specifies a property-tree path to add (duplicates can be added)
* `-v value`: used with -s path or -p path, sets the value at the path
* `-d path`: deletes all subtrees matching the path
* `-a path`: adds a subtree at the path; the subtree is read from stdin
* `-r path`: replaces a subtree at the path; equivalent to -d path followed by -a path

## Sample commands for NFD ##

    ./infoedit -f nfd.conf -s general.user -v ndn.user
    ./infoedit -f nfd.conf -s tables.strategy_choice./site -v /localhost/nfd/strategy/broadcast
    ./infoedit -f nfd.conf -d tables.strategy_choice./
    ./infoedit -f nfd.conf -d authorizations
    ./infoedit -f nfd.conf -a rib.localhost_security <<<EOT
      trust-anchor
      {
        type any
      }
      EOT

### nfd.conf used in above sample ###

    ; comment1

    general ; comment2
    {
        user user ; comment3
        group group
    }

    tables
    {
        strategy_choice
        {
            / /localhost/nfd/strategy/best-route
            /site /localhost/nfd/strategy/broadcast
        }
    }

    authorizations
    {
        authorize
        {
            certfile file1.cert
        }
        authorize
        {
            certfile file2.cert
        }
    }

### nfd.conf after carrying out all commands in above sample ###

    general
    {
        user ndn.user
        group group
    }
    tables
    {
        strategy_choice
        {
            /site /localhost/nfd/strategy/broadcast
        }
    }
    rib
    {
        localhost_security
        {
            trust-anchor
            {
                type any
            }
        }
    }

## Sample commands for NLSR ##

    ./infoedit -f nlsr.conf -d security.cert-to-publish
    ./infoedit -f nlsr.conf -p security.cert-to-publish -v security/root.cert
    ./infoedit -f nlsr.conf -p security.cert-to-publish -v security/site.cert
    ./infoedit -f nlsr.conf -p security.cert-to-publish -v security/operator.cert
    ./infoedit -f nlsr.conf -p security.cert-to-publish -v security/router.cert

### nlsr.conf used in above sample ###

    ...
    security
    {
        ...

        ; cert-to-publish "root.cert"

        ; cert-to-publish "site.cert"

        ; cert-to-publish "operator.cert"

        cert-to-publish "router.cert"
    }

### nlsr.conf after carrying out all commands in above sample ###

    ...
    security
    {
        ...

        cert-to-publish security/root.cert

        cert-to-publish security/site.cert

        cert-to-publish security/operator.cert

        cert-to-publish security/router.cert
    }
