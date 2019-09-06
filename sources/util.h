#ifndef UTIL_H_
#define UTIL_H_

/* prototypes */
int error(const char *);
int *ivector(int, int);
float *vector(int, int);
double *dvector(int, int);
void free_ivector(int *, int, int);
void free_vector(float *, int,int);
void free_dvector(double *, int, int);
void usage(char *);

#endif /* UTIL_H_ */
