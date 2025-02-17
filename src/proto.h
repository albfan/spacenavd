#ifndef PROTO_H_
#define PROTO_H_

/* maximum supported protocol version */
#define MAX_PROTO_VER	1

struct reqresp {
	int type;
	int data[7];
};

#define REQ_TAG			0x7faa0000
#define REQ_BASE		0x1000

/* REQ_S* are set, REQ_G* are get requests.
 * Quick-reference for request-response data in the comments next to each
 * request: Q[n] defines request data item n, R[n] defines response data item n
 *
 * status responses are 0 for success, non-zero for failure
 */
enum {
	/* per-client settings */
	REQ_SET_NAME = REQ_BASE,/* set client name: Q[0-6] name - R[6] status */
	REQ_SET_SENS,			/* set client sensitivity:	Q[0] float - R[6] status */
	REQ_GET_SENS,			/* get client sensitivity:	R[0] float R[6] status */

	/* device queries */
	REQ_DEV_NAME = 0x2000,	/* get device name:	R[0] length R[6] status followed
							   by <length> bytes */
	REQ_DEV_PATH,			/* get device path: same as above */
	REQ_DEV_NAXES,			/* get number of axes:		R[0] num axes R[6] status */
	REQ_DEV_NBUTTONS,		/* get number of buttons: same as above */
	/* TODO: features like LCD, LEDs ... */

	/* configuration settings */
	REQ_SCFG_SENS = 0x3000,	/* set global sensitivity:	Q[0] float - R[6] status */
	REQ_GCFG_SENS,			/* get global sens:			R[0] float R[6] status */
	REQ_SCFG_SENS_AXIS,		/* set per-axis sens/ty:	Q[0-5] values - R[6] status */
	REQ_GCFG_SENS_AXIS,		/* get per-axis sens/ty:	R[0-5] values R[6] status */
	REQ_SCFG_DEADZONE,		/* set deadzones:			Q[0-5] values - R[6] status */
	REQ_GCFG_DEADZONE,		/* get deadzones:			R[0-5] values R[6] status */
	REQ_SCFG_INVERT,		/* set invert axes:			Q[0-5] invert - R[6] status */
	REQ_GCFG_INVERT,		/* get invert axes:			R[0-5] invert R[6] status */
	REQ_SCFG_AXISMAP,		/* set axis mapping:        Q[0] dev axis Q[1] mapping - R[6] status */
	REQ_GCFG_AXISMAP,		/* get axis mapping:		Q[0] dev axis - R[0] dev axis R[1] mapping R[6] status */
	REQ_SCFG_BNMAP,			/* set button mapping:		Q[0] dev bidx Q[1] map bidx - R[6] status */
	REQ_GCFG_BNMAP,			/* get button mapping:		Q[0] dev bidx - R[0] dev bidx R[1] map bidx R[6] status */
	REQ_SCFG_BNACTION,		/* set button action:		Q[0] bidx Q[1] action - R[6] status */
	REQ_GCFG_BNACTION,		/* get button action:		Q[0] bidx - R[0] bidx R[1] action R[6] status */
	REQ_SCFG_KBMAP,			/* set keyboard mapping:	Q[0] bidx Q[1] keysym - R[6] status */
	REQ_GCFG_KBMAP,			/* get keyboard mapping:	Q[0] bidx - R[0] bidx R[1] keysym R[6] status */
	REQ_SCFG_LED,			/* set LED state:			Q[0] state - R[6] status */
	REQ_GCFG_LED,			/* get LED state:			R[0] state R[6] status */
	REQ_SCFG_GRAB,			/* set device grabbing:		Q[0] state - R[6] status */
	REQ_GCFG_GRAB,			/* get device grabbing:		R[0] state R[6] status */
	REQ_SCFG_SERDEV,		/* set serial device path:	Q[0] length, followed by <length> bytes - R[6] status */
	REQ_GCFG_SERDEV,		/* get serial device path:	R[0] length R[6] status, followed by <length> bytes */
	/* TODO ... more */
	REQ_CFG_SAVE = 0x3ffe,	/* save config file:        R[6] status */
	REQ_CFG_RESTORE,		/* load config from file:   R[6] status */

	REQ_CHANGE_PROTO	= 0x5500
};

#endif	/* PROTO_H_ */
