/*
 * Utils.h
 *
 * Created: 08/08/2024 02:57:37 م
 *  Author: HP
 */ 


#ifndef UTILS_H_
#define UTILS_H_


#define SETBIT(reg,bit)  (reg=reg|(1<<bit))
#define GETBIT(reg,bit)  (reg&(1<<bit))
#define CLEARBIT(reg,bit)  (reg=reg&~(1<<bit))
#define TOGGLEBIT(reg,bit)  (reg=reg^(1<<bit))




#endif /* UTILS_H_ */