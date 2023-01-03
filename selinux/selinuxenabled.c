/*
 * selinuxenabled
 *
 * Based on libselinux 1.33.1
 * Port to BusyBox  Hiroshi Shinji <shiroshi@my.email.ne.jp>
 *
 * Licensed under GPLv2, see file LICENSE in this source tree.
 */
//config:config SELINUXENABLED
//config:	bool "selinuxenabled (321 bytes)"
//config:	default n
//config:	help
//config:	Enable support for this command to be used within shell scripts
//config:	to determine if selinux is enabled.

//applet:IF_SELINUXENABLED(APPLET(selinuxenabled, BB_DIR_USR_SBIN, BB_SUID_DROP))

//kbuild:lib-$(CONFIG_SELINUXENABLED) += selinuxenabled.o

//usage:#define selinuxenabled_trivial_usage NOUSAGE_STR
//usage:#define selinuxenabled_full_usage ""

#include "libbb.h"

#ifndef CONFIG_SELINUX
int is_selinux_enabled(void) {
	struct stat st;
	stat("/sys/fs/selinux", &st);

	if (S_ISDIR(st.st_mode))
		return 1;

	return 0;
}
#endif

int selinuxenabled_main(int argc, char **argv) MAIN_EXTERNALLY_VISIBLE;
int selinuxenabled_main(int argc UNUSED_PARAM, char **argv UNUSED_PARAM)
{
	return !is_selinux_enabled();
}
