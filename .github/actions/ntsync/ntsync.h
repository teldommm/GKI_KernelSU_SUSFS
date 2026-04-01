
/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
/*
 * Kernel support for NT synchronization primitives
 *
 * Copyright (C) 2021-2024 Elizabeth Figura <zfigura@codeweavers.com>
 *
 * Backported header for Linux 6.6 (GKI Android).
 */

#ifndef __LINUX_NTSYNC_H
#define __LINUX_NTSYNC_H

#include <linux/types.h>

struct ntsync_sem_args {
	__u32 count;
	__u32 max;
};

struct ntsync_mutex_args {
	__u32 owner;
	__u32 count;
};

struct ntsync_event_args {
	__u32 manual;
	__u32 signaled;
};

#define NTSYNC_WAIT_REALTIME	0x1

struct ntsync_wait_args {
	__u64 timeout;
	__u64 objs;
	__u32 count;
	__u32 owner;
	__u32 index;
	__u32 flags;
	__u32 alert;    /* fd of alert event (0 = none) */
	__u32 pad;
};

#define NTSYNC_MAX_WAIT_COUNT 64

/* Device ioctls */
#define NTSYNC_IOC_CREATE_SEM		_IOWR('N', 0x80, struct ntsync_sem_args)
#define NTSYNC_IOC_CREATE_MUTEX		_IOWR('N', 0x81, struct ntsync_mutex_args)
#define NTSYNC_IOC_CREATE_EVENT		_IOWR('N', 0x82, struct ntsync_event_args)
#define NTSYNC_IOC_WAIT_ANY		_IOWR('N', 0x83, struct ntsync_wait_args)
#define NTSYNC_IOC_WAIT_ALL		_IOWR('N', 0x84, struct ntsync_wait_args)

/* Object ioctls — names as used in ntsync.c */
#define NTSYNC_IOC_SEM_RELEASE		_IOWR('N', 0x88, __u32)
#define NTSYNC_IOC_SEM_READ		_IOR ('N', 0x89, struct ntsync_sem_args)
#define NTSYNC_IOC_MUTEX_UNLOCK		_IOWR('N', 0x8a, struct ntsync_mutex_args)
#define NTSYNC_IOC_MUTEX_KILL		_IOW ('N', 0x8b, __u32)
#define NTSYNC_IOC_MUTEX_READ		_IOR ('N', 0x8c, struct ntsync_mutex_args)
#define NTSYNC_IOC_EVENT_SET		_IOR ('N', 0x8d, struct ntsync_event_args)
#define NTSYNC_IOC_EVENT_RESET		_IOR ('N', 0x8e, struct ntsync_event_args)
#define NTSYNC_IOC_EVENT_PULSE		_IOR ('N', 0x8f, struct ntsync_event_args)
#define NTSYNC_IOC_EVENT_READ		_IOR ('N', 0x90, struct ntsync_event_args)
#define NTSYNC_IOC_KILL_OWNER		_IOW ('N', 0x91, __u32)

#endif /* __LINUX_NTSYNC_H */
