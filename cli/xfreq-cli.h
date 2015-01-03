/*
 * xfreq-cli.h by CyrIng
 *
 * Copyright (C) 2013-2015 CYRIL INGENIERIE
 * Licenses: GPL2
 */


#if defined(FreeBSD)
// Posix fix.
#define	pthread_setname_np pthread_set_name_np
#define	pthread_tryjoin_np(t, r) pthread_timedjoin_np(t, r, 0)
#endif

#define	OPTIONS_COUNT	4
typedef struct
{
	char		*argument;
	char		*format;
	void		*pointer;
	char		*manual;
} OPTIONS;

typedef struct
{
	int		FD;
	SHM_STRUCT	*SHM;
	unsigned int	Room;

	sigset_t	Signal;
	pthread_t	TID_SigHandler,
			TID_Read;

	bool		LOOP;
	OPTIONS		Options[OPTIONS_COUNT];
} uARG;
