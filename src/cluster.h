/* At least for the things in C */

#include <R_ext/Boolean.h>

/* in ./meet.f --- called from most source files: */
int meet_(int *, int *);

/* --------- ./clara.c ------------------*/

double randm(int *nrun);

void clara(int *n,  /* = number of objects */
	   int *jpp,/* = number of variables */
	   int *kk, /* = number of clusters, 1 <= kk <= n-1 */
	   double *x,	/* Input:  the data x[n, jpp] _rowwise_ (transposed)
			 * Output: the first `n' values are the `clustering'
			 *	   (integers in 1,2,..,kk) */
	   int *nran,	/* = #{random samples} drawn	   (= `samples' in R)*/
	   int *nsam,	/* = #{objects} drawn from data set (`sampsize' in R) */
	   double *dys,/* [1:(1 + (nsam * (nsam - 1))/2)]
			* Output: to contain the distances */
	   int *mdata,	/*= {0,1}; 1: min(x) is missing value (NA);  0: no NA */
	   double *valmd,/*[j]= missing value code (instead of NA) for x[,j]*/
	   int *jtmd,	/* [j]= {-1,1};	 -1: x[,j] has NA; 1: no NAs in x[,j] */
	   int *diss_kind,/* = {1,2};  1 : euclidean;  2 : manhattan*/
	   int *nrepr,	/* */
	   int *nsel, int *nbest,
	   int *nr, int *nrx,
	   double *radus, double *ttd, double *ratt,
	   double *ttbes, double *rdbes, double *rabes,
	   int *mtt, double *obj,
	   double *avsyl, double *ttsyl, double *sylinf,
	   int *jstop, int *trace_lev,
	   double *tmp, /* = double [ 3 * nsam ] */
	   int *itmp	/* = integer[ 6 * nsam ] */
    );

void dysta2(int nsam, int jpp, int *nsel,
	    double *x, int n, double *dys, int diss_kind,
	    int *jtmd, double *valmd, int *jhalt);

void bswap2(int kk, int nsam, int *nrepr,
	    double *dys, double *sky, double s,
	    double *dysma, double *dysmb, double *beter);

void selec(int kk, int n, int jpp, int diss_kind,
	   double *zb, int nsam, Rboolean has_NA, int *jtmd, double *valmd,
	   int *nrepr, int *nsel, double *dys, double *x, int *nr,
	   Rboolean *nafs, double *ttd, double *radus, double *ratt,
	   int *nrnew, int *nsnew, int *npnew, int *ns, int *np, int *new,
	   double *ttnew, double *rdnew);

void resul(int kk, int n, int jpp, int diss_kind, Rboolean has_NA,
	   int *jtmd, double *valmd, double *x, int *nrx, int *mtt);

void black(int kk, int jpp, int nsam, int *nbest,
	   double *dys, double s, double *x,
	   /* --> Output : */
	   double *avsyl, double *ttsyl, double *sylinf,
	   int *ncluv, int *nsend, int *nelem, int *negbr,
	   double *syl, double *srank);

/* --------- ./spannel.c ------------------*/

void sweep(double *, int *, int *, int *, double *);

void spannel(int *ncas, /* = number of objects */
	     int *ndep, /* = number of variables */
	     double *dat,/* [ncas, 0:ndep] */
	     double *dstopt, /* = squared distances [1:ncas] */
	     double *cov,/* matrix [0:ndep, 0:ndep] */
	     double *varsum,	/* [1:ndep] */
	     double *varss,	/* [1:ndep] */
	     double *prob,	/* [1:ncas] */
	     double *work,	/* [0:ndep] */
	     double *eps,
	     int *maxit, /* = maximal # iterations (and returns #{iter.})*/
	     int *ierr);
