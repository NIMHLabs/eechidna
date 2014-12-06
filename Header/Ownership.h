/*
 * = eEchidna User Handler:Header/Ownership.h
 * Author: KatrinaTheLamia
 * Creation: Decembre 6th 2014
 *
 * This is a simply variation of how Android handles its process managing
 * to allow for multiuser usage. As I do enjoy the added security that 
 * Android adds to keep its software from looking at other software's space
 * just be a bit of an exploit of Linux' userspace functionalities. However
 * this makes a multiuser system nigh impossible for Android to run.
 *
 * == Revisions
 * !+ Decembre 6th 2014
 * * Started a rough draft of the file
 *
 * == Todo
 * !+ Decembre 6th 2014
 * * Make not suck of shitty fail
 * * Debug
 * * Document
 */


/* So... let's start this file thing then
 */
#ifndef __eEchidna_Userhandling_Ownership_H__
#define __eEchidna_Userhandling_Ownership_H__

#ifdef __cplusplus
extern "C"
{
#endif

typedef void* edna_memoryhandling_wtf;

typedef unsigned int identification;


typedef struct __edna_ownerinfo_d
{
   edna_memory_handling_wtf myself;
   identification application_id, /* Should match up to gid in linux kernel */
                  process_id, /* Should match up with uid in linux kernel */
                  user_id, /* eEchidna User Id that applications all own into*/
                  group_id, /* eEchidna Group Id that users all own into */
                  purchase_id, /* Somebody else could have purchased it */
                  organisation_id; /* With Mainfra^H^H^H^H^H^H^H^ Cloud 
                                    * Computing coming back... could be a 
                                    * useful addition. */
} _edna_ownerinfo_s;
typedef _edna_ownerinfo_s* edna_ownerinfo_ps;

/* This is for the linker's purpose entirely.
 * This will likely create a version of this data structure, as a 
 * per process type entry.
 */
edna_ownerinfo_ps begin(void);

/* Constructor functions...*/
edna_ownerinfo_ps create(void);
edna_ownerinfo_ps create(identification,
                         identification, 
                         identification,
                         identification,
                         identification,
                         identification);
void destroy(edna_ownerinfo_ps);

/* There is a chance we can have the linker create this functions... 
 * However, I should write this stuff out, to get my programming hears moving
 * some more.
 */
identification get_application_id(edna_ownerinfo_ps);
identification get_process_id(edna_ownerinfo_ps);
identification get_user_id(edna_ownerinfo_ps);
identification get_group_id(edna_ownerinfo_ps);
identification get_purchase_id(edna_ownerinfo_ps);
idenfitication get_organisation_id(edna_ownerinfo_ps);

/* This... module is kind of ridiculous... but... fuck it, I guess? */

#ifdef __cplusplus
}
#endif


#endif
