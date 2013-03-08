/**
 * @file
 * @brief
 *
 * @date 26.02.13
 * @author Ilia Vaprol
 */

#ifndef CURSES_H_
#define CURSES_H_

#include <sys/cdefs.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

__BEGIN_DECLS

#define TRUE  true
#define FALSE false

#define OK   0
#define ERR -1

typedef unsigned long chtype;
typedef unsigned long attr_t;

typedef struct window {
	uint16_t cury, curx; /* cursor position */
	uint16_t begy, begx; /* left upper window corner */
	uint16_t endy, endx; /* right lower window corner */
	struct window *parent;
	attr_t attrs;
	chtype bkgd;         /* background color */
	chtype *lines;
	bool scrollok;       /* may scroll */
	bool clearok;        /* clear screen on next refresh */
} WINDOW;

typedef unsigned long mmask_t;

extern int COLS;
extern int LINES;
extern WINDOW *curscr;
extern WINDOW *stdscr;

extern WINDOW * initscr(void);
extern WINDOW * newwin(int nlines, int ncols, int begin_y,
		int begin_x);
extern WINDOW * subwin(WINDOW *orig, int nlines, int ncols,
		int begin_y, int begin_x);
extern WINDOW * derwin(WINDOW *orig, int nlines, int ncols,
		int begin_y, int begin_x);
extern int delwin(WINDOW *win);
extern int doupdate(void);
extern int refresh(void);
extern int wnoutrefresh(WINDOW *win);
extern int wrefresh(WINDOW *win);
extern int move(int y, int x);
extern int wmove(WINDOW *win, int y, int x);
extern int addch(const chtype ch);
extern int mvaddch(int y, int x, const chtype ch);
extern int mvwaddch(WINDOW *win, int y, int x, const chtype ch);
extern int waddch(WINDOW *win, const chtype ch);
extern int addnstr(const char *str, int n);
extern int addstr(const char *str);
extern int mvaddnstr(int y, int x, const char *str, int n);
extern int mvaddstr(int y, int x, const char *str);
extern int mvwaddnstr(WINDOW *win, int y, int x, const char *str, int n);
extern int mvwaddstr(WINDOW *win, int y, int x, const char *str);
extern int waddnstr(WINDOW *win, const char *str, int n);
extern int waddstr(WINDOW *win, const char *str);
extern int scrl(int n);
extern int scroll(WINDOW *win);
extern int wscrl(WINDOW *win, int n);
extern int scrollok(WINDOW *win, bool bf);
extern int clearok(WINDOW *win, bool bf);
extern int clear(void);
extern int erase(void);
extern int wclear(WINDOW *win);
extern int werase(WINDOW *win);
extern int attroff(int attrs);
extern int attron(int attrs);
extern int attrset(int attrs);
extern int wattroff(WINDOW *win, int attrs);
extern int wattron(WINDOW *win, int attrs);
extern int wattrset(WINDOW *win, int attrs);
extern int delch(void);
extern int mvdelch(int y, int x);
extern int mvwdelch(WINDOW *win, int y, int x);
extern int wdelch(WINDOW *win);
extern int getch(void);
extern int mvgetch(int y, int x);
extern int mvwgetch(WINDOW *win, int y, int x);
extern int wgetch(WINDOW *win);
extern int bkgd(chtype ch);
extern void bkgdset(chtype ch);
extern chtype getbkgd(WINDOW *win);
extern int wbkgd(WINDOW *win, chtype ch);
extern void wbkgdset(WINDOW *win, chtype ch);


#define KEY_DOWN	0402		/* down-arrow key */
#define KEY_UP		0403		/* up-arrow key */
#define KEY_LEFT	0404		/* left-arrow key */
#define KEY_RIGHT	0405		/* right-arrow key */
#define KEY_HOME	0406		/* home key */
#define KEY_BACKSPACE	0407		/* backspace key */
#define KEY_F0		0410		/* Function keys.  Space for 64 */
#define KEY_F(n)	(KEY_F0+(n))	/* Value of function key n */
#define KEY_DL		0510		/* delete-line key */
#define KEY_IL		0511		/* insert-line key */
#define KEY_DC		0512		/* delete-character key */
#define KEY_IC		0513		/* insert-character key */
#define KEY_EIC		0514		/* sent by rmir or smir in insert mode */
#define KEY_CLEAR	0515		/* clear-screen or erase key */
#define KEY_EOS		0516		/* clear-to-end-of-screen key */
#define KEY_EOL		0517		/* clear-to-end-of-line key */
#define KEY_SF		0520		/* scroll-forward key */
#define KEY_SR		0521		/* scroll-backward key */
#define KEY_NPAGE	0522		/* next-page key */
#define KEY_PPAGE	0523		/* previous-page key */
#define KEY_STAB	0524		/* set-tab key */
#define KEY_CTAB	0525		/* clear-tab key */
#define KEY_CATAB	0526		/* clear-all-tabs key */
#define KEY_ENTER	0527		/* enter/send key */
#define KEY_PRINT	0532		/* print key */
#define KEY_LL		0533		/* lower-left key (home down) */
#define KEY_A1		0534		/* upper left of keypad */
#define KEY_A3		0535		/* upper right of keypad */
#define KEY_B2		0536		/* center of keypad */
#define KEY_C1		0537		/* lower left of keypad */
#define KEY_C3		0540		/* lower right of keypad */
#define KEY_BTAB	0541		/* back-tab key */
#define KEY_BEG		0542		/* begin key */
#define KEY_CANCEL	0543		/* cancel key */
#define KEY_CLOSE	0544		/* close key */
#define KEY_COMMAND	0545		/* command key */
#define KEY_COPY	0546		/* copy key */
#define KEY_CREATE	0547		/* create key */
#define KEY_END		0550		/* end key */
#define KEY_EXIT	0551		/* exit key */
#define KEY_FIND	0552		/* find key */
#define KEY_HELP	0553		/* help key */
#define KEY_MARK	0554		/* mark key */
#define KEY_MESSAGE	0555		/* message key */
#define KEY_MOVE	0556		/* move key */
#define KEY_NEXT	0557		/* next key */
#define KEY_OPEN	0560		/* open key */
#define KEY_OPTIONS	0561		/* options key */
#define KEY_PREVIOUS	0562		/* previous key */
#define KEY_REDO	0563		/* redo key */
#define KEY_REFERENCE	0564		/* reference key */
#define KEY_REFRESH	0565		/* refresh key */
#define KEY_REPLACE	0566		/* replace key */
#define KEY_RESTART	0567		/* restart key */
#define KEY_RESUME	0570		/* resume key */
#define KEY_SAVE	0571		/* save key */
#define KEY_SBEG	0572		/* shifted begin key */
#define KEY_SCANCEL	0573		/* shifted cancel key */
#define KEY_SCOMMAND	0574		/* shifted command key */
#define KEY_SCOPY	0575		/* shifted copy key */
#define KEY_SCREATE	0576		/* shifted create key */
#define KEY_SDC		0577		/* shifted delete-character key */
#define KEY_SDL		0600		/* shifted delete-line key */
#define KEY_SELECT	0601		/* select key */
#define KEY_SEND	0602		/* shifted end key */
#define KEY_SEOL	0603		/* shifted clear-to-end-of-line key */
#define KEY_SEXIT	0604		/* shifted exit key */
#define KEY_SFIND	0605		/* shifted find key */
#define KEY_SHELP	0606		/* shifted help key */
#define KEY_SHOME	0607		/* shifted home key */
#define KEY_SIC		0610		/* shifted insert-character key */
#define KEY_SLEFT	0611		/* shifted left-arrow key */
#define KEY_SMESSAGE	0612		/* shifted message key */
#define KEY_SMOVE	0613		/* shifted move key */
#define KEY_SNEXT	0614		/* shifted next key */
#define KEY_SOPTIONS	0615		/* shifted options key */
#define KEY_SPREVIOUS	0616		/* shifted previous key */
#define KEY_SPRINT	0617		/* shifted print key */
#define KEY_SREDO	0620		/* shifted redo key */
#define KEY_SREPLACE	0621		/* shifted replace key */
#define KEY_SRIGHT	0622		/* shifted right-arrow key */
#define KEY_SRSUME	0623		/* shifted resume key */
#define KEY_SSAVE	0624		/* shifted save key */
#define KEY_SSUSPEND	0625		/* shifted suspend key */
#define KEY_SUNDO	0626		/* shifted undo key */
#define KEY_SUSPEND	0627		/* suspend key */
#define KEY_UNDO	0630		/* undo key */
#define KEY_MOUSE	0631		/* Mouse event has occurred */
#define KEY_RESIZE	0632		/* Terminal resize event */
#define KEY_EVENT	0633		/* We were interrupted by an event */
#define KEY_MAX		0777		/* Maximum key value is 0633 */

#define A_NORMAL	0x0000
#define A_REVERSE   0x1000
#define A_BOLD      0x2000

__END_DECLS

#endif /* CURSES_H_ */
