/*-
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2022 Alexander V. Chernikov <melifaro@FreeBSD.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/*
 * Common defines for all parts of the NETLINK_ROUTE family
 */
#ifndef _NETLINK_ROUTE_COMMON_H_
#define _NETLINK_ROUTE_COMMON_H_

/* Defined NETLINK_ROUTE messages */
enum {
	NL_RTM_BASE		= 16,
	NL_RTM_NEWLINK		= 16, /* creates new interface */
	NL_RTM_DELLINK		= 17, /* deletes matching interface */
	NL_RTM_GETLINK		= 18, /* lists matching interfaces */
	NL_RTM_SETLINK		= 19, /* not supported */
	NL_RTM_NEWADDR		= 20, /* not supported */
	NL_RTM_DELADDR		= 21, /* not supported */
	NL_RTM_GETADDR		= 22, /* lists matching ifaddrs */
	NL_RTM_NEWROUTE		= 24, /* adds or changes a route */
	NL_RTM_DELROUTE		= 25, /* deletes matching route */
	NL_RTM_GETROUTE		= 26, /* lists matching routes */
	NL_RTM_NEWNEIGH		= 28, /* creates new arp/ndp entry */
	NL_RTM_DELNEIGH		= 29, /* deletes matching arp/ndp entry */
	NL_RTM_GETNEIGH		= 30, /* lists matching arp/ndp entry */
	NL_RTM_NEWRULE		= 32, /* not supported */
	NL_RTM_DELRULE		= 33, /* not supported */
	NL_RTM_GETRULE		= 34, /* not supported */
	NL_RTM_NEWQDISC		= 36, /* not supported */
	NL_RTM_DELQDISC		= 37, /* not supported */
	NL_RTM_GETQDISC		= 38, /* not supported */
	NL_RTM_NEWTCLASS	= 40, /* not supported */
	NL_RTM_DELTCLASS	= 41, /* not supported */
	NL_RTM_GETTCLASS	= 42, /* not supported */
	NL_RTM_NEWTFILTER	= 44, /* not supported */
	NL_RTM_DELTFILTER	= 45, /* not supported */
	NL_RTM_GETTFILTER	= 46, /* not supported */
	NL_RTM_NEWACTION	= 48, /* not supported */
	NL_RTM_DELACTION	= 49, /* not supported */
	NL_RTM_GETACTION	= 50, /* not supported */
	NL_RTM_NEWPREFIX	= 52, /* not supported */
	NL_RTM_GETMULTICAST	= 58, /* not supported */
	NL_RTM_GETANYCAST	= 62, /* not supported */
	NL_RTM_NEWNEIGHTBL	= 64, /* not supported */
	NL_RTM_GETNEIGHTBL	= 66, /* not supported */
	NL_RTM_SETNEIGHTBL	= 67, /* not supported */
	NL_RTM_NEWNDUSEROPT	= 68, /* not supported */
	NL_RTM_NEWADDRLABEL	= 72, /* not supported */
	NL_RTM_DELADDRLABEL	= 73, /* not supported */
	NL_RTM_GETADDRLABEL	= 74, /* not supported */
	NL_RTM_GETDCB		= 78, /* not supported */
	NL_RTM_SETDCB		= 79, /* not supported */
	NL_RTM_NEWNETCONF	= 80, /* not supported */
	NL_RTM_GETNETCONF	= 82, /* not supported */
	NL_RTM_NEWMDB		= 84, /* not supported */
	NL_RTM_DELMDB		= 85, /* not supported */
	NL_RTM_GETMDB		= 86, /* not supported */
	NL_RTM_NEWNSID		= 88, /* not supported */
	NL_RTM_DELNSID		= 89, /* not supported */
	NL_RTM_GETNSID		= 90, /* not supported */
	NL_RTM_NEWSTATS		= 92, /* not supported */
	NL_RTM_GETSTATS		= 94, /* not supported */
	NL_RTM_NEWNEXTHOP	= 104, /* creates new user nexhtop */
	NL_RTM_DELNEXTHOP	= 105, /* deletes matching nexthop */
	NL_RTM_GETNEXTHOP	= 106, /* lists created user nexthops */
	__NL_RTM_MAX,
};
#define NL_RTM_MAX (((__NL_RTM_MAX + 3) & ~3) - 1)

#ifndef _KERNEL
/*
 * RTM_* namespace clashes with BSD rtsock namespace.
 * Use NL_RTM_ prefix in the kernel and map it to RTM_
 * for userland.
 */
#define RTM_BASE	NL_RTM_BASE
#define RTM_NEWLINK 	NL_RTM_NEWLINK
#define RTM_DELLINK 	NL_RTM_DELLINK
#define RTM_GETLINK 	NL_RTM_GETLINK
#define RTM_SETLINK 	NL_RTM_SETLINK
#define RTM_NEWADDR	NL_RTM_NEWADDR
#define RTM_DELADDR	NL_RTM_DELADDR
#define RTM_GETADDR 	NL_RTM_GETADDR
#define RTM_NEWROUTE 	NL_RTM_NEWROUTE
#define RTM_DELROUTE 	NL_RTM_DELROUTE
#define RTM_GETROUTE 	NL_RTM_GETROUTE
#define	RTM_NEWNEXTHOP	NL_RTM_NEWNEXTHOP
#define	RTM_DELNEXTHOP	NL_RTM_DELNEXTHOP
#define	RTM_GETNEXTHOP	NL_RTM_GETNEXTHOP
#endif

#ifndef _KERNEL
/* rtnetlink multicast groups - backwards compatibility for userspace */
#define RTMGRP_LINK		0x01
#define RTMGRP_NOTIFY		0x02
#define RTMGRP_NEIGH		0x04
#define RTMGRP_TC		0x08

#define RTMGRP_IPV4_IFADDR	0x10
#define RTMGRP_IPV4_MROUTE	0x20
#define RTMGRP_IPV4_ROUTE	0x40
#define RTMGRP_IPV4_RULE	0x80

#define RTMGRP_IPV6_IFADDR	0x100
#define RTMGRP_IPV6_MROUTE	0x200
#define RTMGRP_IPV6_ROUTE	0x400
#define RTMGRP_IPV6_IFINFO	0x800

#define RTMGRP_DECnet_IFADDR	0x1000
#define RTMGRP_DECnet_ROUTE	0x4000

#define RTMGRP_IPV6_PREFIX	0x20000
#endif

/* Defined NETLINK_ROUTE multicast groups */
enum rtnetlink_groups {
	RTNLGRP_NONE,
#define RTNLGRP_NONE		RTNLGRP_NONE
	RTNLGRP_LINK,
#define RTNLGRP_LINK		RTNLGRP_LINK
	RTNLGRP_NOTIFY,
#define RTNLGRP_NOTIFY		RTNLGRP_NOTIFY
	RTNLGRP_NEIGH,
#define RTNLGRP_NEIGH		RTNLGRP_NEIGH
	RTNLGRP_TC,
#define RTNLGRP_TC		RTNLGRP_TC
	RTNLGRP_IPV4_IFADDR,
#define RTNLGRP_IPV4_IFADDR	RTNLGRP_IPV4_IFADDR
	RTNLGRP_IPV4_MROUTE,
#define RTNLGRP_IPV4_MROUTE	RTNLGRP_IPV4_MROUTE
	RTNLGRP_IPV4_ROUTE,
#define RTNLGRP_IPV4_ROUTE	RTNLGRP_IPV4_ROUTE
	RTNLGRP_IPV4_RULE,
#define RTNLGRP_IPV4_RULE	RTNLGRP_IPV4_RULE
	RTNLGRP_IPV6_IFADDR,
#define RTNLGRP_IPV6_IFADDR	RTNLGRP_IPV6_IFADDR
	RTNLGRP_IPV6_MROUTE,
#define RTNLGRP_IPV6_MROUTE	RTNLGRP_IPV6_MROUTE
	RTNLGRP_IPV6_ROUTE,
#define RTNLGRP_IPV6_ROUTE	RTNLGRP_IPV6_ROUTE
	RTNLGRP_IPV6_IFINFO,
#define RTNLGRP_IPV6_IFINFO	RTNLGRP_IPV6_IFINFO
	RTNLGRP_DECnet_IFADDR,
#define RTNLGRP_DECnet_IFADDR	RTNLGRP_DECnet_IFADDR
	RTNLGRP_NOP2,
	RTNLGRP_DECnet_ROUTE,
#define RTNLGRP_DECnet_ROUTE	RTNLGRP_DECnet_ROUTE
	RTNLGRP_DECnet_RULE,
#define RTNLGRP_DECnet_RULE	RTNLGRP_DECnet_RULE
	RTNLGRP_NOP4,
	RTNLGRP_IPV6_PREFIX,
#define RTNLGRP_IPV6_PREFIX	RTNLGRP_IPV6_PREFIX
	RTNLGRP_IPV6_RULE,
#define RTNLGRP_IPV6_RULE	RTNLGRP_IPV6_RULE
	RTNLGRP_ND_USEROPT,
#define RTNLGRP_ND_USEROPT	RTNLGRP_ND_USEROPT
	RTNLGRP_PHONET_IFADDR,
#define RTNLGRP_PHONET_IFADDR	RTNLGRP_PHONET_IFADDR
	RTNLGRP_PHONET_ROUTE,
#define RTNLGRP_PHONET_ROUTE	RTNLGRP_PHONET_ROUTE
	RTNLGRP_DCB,
#define RTNLGRP_DCB		RTNLGRP_DCB
	RTNLGRP_IPV4_NETCONF,
#define RTNLGRP_IPV4_NETCONF	RTNLGRP_IPV4_NETCONF
	RTNLGRP_IPV6_NETCONF,
#define RTNLGRP_IPV6_NETCONF	RTNLGRP_IPV6_NETCONF
	RTNLGRP_MDB,
#define RTNLGRP_MDB 		RTNLGRP_MDB
	RTNLGRP_MPLS_ROUTE,
#define RTNLGRP_MPLS_ROUTE	RTNLGRP_MPLS_ROUTE
	RTNLGRP_NSID,
#define RTNLGRP_NSID		RTNLGRP_NSID
	RTNLGRP_MPLS_NETCONF,
#define RTNLGRP_MPLS_NETCONF	RTNLGRP_MPLS_NETCONF
	RTNLGRP_IPV4_MROUTE_R,
#define RTNLGRP_IPV4_MROUTE_R	RTNLGRP_IPV4_MROUTE_R
	RTNLGRP_IPV6_MROUTE_R,
#define RTNLGRP_IPV6_MROUTE_R	RTNLGRP_IPV6_MROUTE_R
	RTNLGRP_NEXTHOP,
#define RTNLGRP_NEXTHOP		RTNLGRP_NEXTHOP
	RTNLGRP_BRVLAN,
#define RTNLGRP_BRVLAN		RTNLGRP_BRVLAN
	__RTNLGRP_MAX
};
#define RTNLGRP_MAX (__RTNLGRP_MAX - 1)


#endif

