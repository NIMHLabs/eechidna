/*
 * =HEAD1 eEchidna's Network Location.h
 * Author:= KatrinaTheLamia
 * CreatedOn:= 2014.04.29
 *
 * Alright... beginning this project as no piece of software I seem to run
 * does anything more than operate like ass. Kind of out of practice so the 
 * first couple entries in this project will look like goats ass. Kind of 
 * sexy if you are skilled enough to know what to look for in the potential
 * of making a good time anywhere... but generally ugly to most people.
 *
 */

#ifndef __eEchidna_Network_Location_H__
#define __eEchidna_Network_Location_H__

/*We shall code C in the shade*/
#ifdef __cplusplus
extern "C"
{
#endif

/* We will probably create a better set of macros to make this Drakania 
 * Compatible */

typedef void* edna_callback;
typedef edna_callback* edna_friends;
/* 
 * Note to self: write better socket handler that keeps track of this...
 * No wait, this entire file will be scrapped if I do that. I'll still 
 * post this file, but I'll think this better way over in a new revision.
 * Remember: I'm still not quite up to doing this stuff properly yet.
 * Let's get those programming muscles stretched out first.
 * */
typedef FILE* edna_nine_handler;
typedef edna_nine_handler* edna_nines_handler_AF;

typedef enum __edna_activity_dat
{
   active,
   closed,
   open,
   timed_out,
   old,
   reaped,
   amnesiac,
} edna_activity_e;


typedef struct __edna_call_location_dat
{
    char *callstring;
    unsigned int *address;
    edna_friends aliases;
} edna_call_location_s;
typedef edna_call_location_s* edna_call_location_ps;
typedef edna_call_location_ps* edna_call_book_Aps;

typedef struct __edna_connection_dat
{
    edna_call_location_ps call_point;
    edna_call_book_Aps direct_communicates;
    edna_nine_handler call_point;
    edna_nines_handler direct_copy_points;
    edna_activity_e activity;
    char *upwards_buffer, *downwards_buffer;
    int up_buffer_len, down_buffer_len;
} edna_connection_s;
typedef edna_connection_s* edna_connection_ps;

/* Yeah... so far this is ridiculously stupid and trivial. Bear with me while
 * I get my programming muscles back from atrophy, enyo dammit! */

/*
 * Constructor function prototypes in C? MADNESS!
 */
edna_call_location_ps create(void);
edna_connection_ps create(void);

/*
 * Get/Set functions. Keep in mind, part of how eEchidna works is heavily
 * based upon side effects. In fact... everything in eEchidna is enginnered
 * to take into account side effects... or it will rather. Once I stop
 * sucking so much at this.
 */
void callstring( edna_location_ps, char* );
void address( edna_location_ps, int* );
void pair( edna_location_ps,
           edna_location_ps );

void unredundant( edna_call_book_Aps );

void call_location( edna_connection_ps,
                    edna_location_ps );
void add_direct_communicate( edna_connection_ps,
                             edna_location_ps );
void remove_direct_communicate( edna_connection_ps,
                                edna_location_ps );
void call_point( edna_connection_ps,
                 edna_nine_handler );
void add_copy_point( edna_connection_ps,
                     edna_nine_handler );
void modify_activity( edna_connection_ps,
                      edna_activity_e );
void read_buffer( edna_connection_ps,
                  int );
void write_buffer( edna_connection_ps,
                   char*,
                   int );

/* So yeah... standard preschool network wrapper file. I'm still really out of
 * shape. I'll work to keep posting shitty files onto this project... until 
 * the files get less shitty */


#ifdef __cplusplus
}
#endif
/*Go back to what the rest of the headers are*/

#endif /* The File */
