/* = eEchidna DOM-Muse Headers Fundamentals.h
 * Author: Katrina Payne
 * Creation: 2014 June 23
 *
 * Holy crap... this is painful to watch getting made, I am so certain.
 * Seriously... this... just... oooh!
 *
 * Soon I'll not suck as much as programming. Just holy crap am I totally
 * out of practice on this stuff here. Give it a bit... give a bit, so 
 * that the awesome can return
 *
 * == Revisions
 * === 2014 June 23
 * Created this file
 *
 * == TODO
 * * Make this not suck
 *
 * */

#ifndef __eEchidna_DOM_Muse_Headers_Fundamentals_H__
#define __eEchidna_DOM_Muse_Headers_Fundamentals_H__
/*Begin the file*/

#include <BasicTypes.h>

#ifdef __cplusplus
extern "C"
{
#endif /* C shall blot out the C++ */

/*
 * So... it looks like an exception is just a standard number that links to a 
 * predefined error functionality.
 *
 * Wow... that... that... just... wow...
 *
 * This reminds me that I'm going to need to figure out some form of internal
 * logging capacity within eEchidna
 * */
typedef enum __edna_DOMException_dat
{
   edna_Index_Size_Error = 1;
   edna_DOMString_Size_Error = 2;
   edna_Heirarchy_Requiest_Error = 3;
   edna_Wrong_Document_Error = 4;
   edna_Invalid_Character_Error = 5;
   edna_No_Data_Allowed_Error = 6;
   edna_No_Modification_Allowed_Error = 7;
   edna_Not_Found_Error = 8;
   edna_Not_Supported_Error = 9;
   edna_In_Use_Attribute_Error = 10;
   /* Here we go... DOM2 introduced codes! HOORAY! */
   edna_Invalid_State_Error = 11;
   edna_Syntax_Error = 12;
   edna_Invalid_Modification_Error = 13;
   edna_Namespace_Error = 14;
   edna_Invalid_Access_Error = 15;
   /* Finally... codes introduced with DOM3 */
   edna_Validation_Error = 16;
   edna_Type_Mismatch_Error = 17;
} edna_DOMException_e;
/*
 * Somehow... I imagine somebody who knows DOM ridiculously well somewhere 
 * is weeping at how I tried to handle this whole thing... and how it totally 
 * breaks conventions
 *
 * That... is not a good thing.
 *
 * Broken Conventions make for strange errors... avoid it if possible
 * */

typedef struct __edna_DOMStringList_dat
{
   edna_DOMString* strings;
   unsigned long length;
   
} edna_DOMStringList_s;
typedef edna_DOMStringList_s* edna_DOMStringList_ps;


edna_DOMStringList_ps create();
edna_DOMStringList_ps create(edna_DOMStringList_ps);

void push(edna_DOMStringList_ps, 
          edna_DOMString);
void unshift(edna_DOMStringList_ps,
             edna_DOMString);
bool contains(edna_DOMStringList_ps,
              edna_DOMString);
edna_DOMString item(edna_DOMStringList_ps,
                    unsigned long);
void remove(edna_DOMStringList_ps,
            unsigned long);

/* You know... these are all defined as "interface" operations 
 * I think I might stop and think and ponder about how an interface 
 * functionality would best be written to be a feature of this 
 * Sybilline Machine.
 *
 * I'm gonna rest this for a bit... and consider the package manager
 * and how to handle this exactly in an eEchidna code style manner.
 * */

#ifdef __cplusplus
}
#endif /* Then we shall code C++ in the shade */

#endif /* End the file */

