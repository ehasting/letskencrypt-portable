/*
 * If your system doesn't use "nobody" as a privilege separated user,
 * then change it here or in the GNUmakefile.
 */
#ifndef NOBODY_USER
# define NOBODY_USER "nobody"
#endif

/*
 * You can define this if your system has its /var/empty elsewhere.
 */
/* #define PATH_VAR_EMPTY "/var/empty" */

/*
 * Require libbsd's stdlib.h for arc4random() etc.
 * Require <grp.h> for setgroups().
 */
#ifdef __linux__
# define _GNU_SOURCE
# include <bsd/stdlib.h>
# include <bsd/string.h>
# include <grp.h>
#endif

/*
 * Apple and NetBSD haven't got these.
 */
#if defined(__APPLE__) || defined(__NetBSD__)
# include <unistd.h>
int	setresgid(gid_t, gid_t, gid_t);
int	setresuid(gid_t, gid_t, gid_t);
#endif

/*
 * FreeBSD goop.
 */
#ifdef __FreeBSD__
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <resolv.h>
#endif
