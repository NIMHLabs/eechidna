/*
 * = eEchidna HitMEL-Intaker:Header/Streamer.h
 * Author: KatrinaTheLamia
 * Creation: Decembre 6th 2014
 *
 * HitMEL Streamer is mostly just a poorly concieved set of items 
 * designed to try to gather HitMEL data from an input stream of some 
 * text form... or form that could possibly be converted to text form
 * or something that honestly, I have no clue as to what I am doing right now.
 * Give me a moment to get my programming muscles going.
 *
 * == Revisions
 * +! Decembre 6th 2014
 * *Poorly concieved file creation
 * 
 * == Todo
 * +! Decembre 6th 2014
 * * Make this not suck
 * * Debug
 * * Document 
 *
 */

/* File Starts */
#ifdef __eEchidna_HitMEL_Instake_Streamer_H__
#define __eEchidna_HitMEL_Instake_Streamer_H__

/* This is C Code, okay? */
#ifdef __cplusplus
extern "C"
{
#endif

/* Just a quick reminder:
 * Any variable of the type "WTF" is to be handled by a seperate
 * framework, that can be accessible via the linker service. To speed 
 * things up, once I have beta version of eEchidna in action I'll 
 * release header variations specifically designed to have function 
 * prototypes for anything that requires something from the linker.
 */

/* Memory handling is specifically to let eEchidna's memory handling 
 * service be aware of something here. Still cannot remember how I was 
 * planning on working that around. Probably requiring a pointer to the 
 * object being passed to the memory handling service, to figure out what 
 * is going on with it. */
typedef void* edna_memoryhandling_wtf;
/* We shall have string handling controlled elsewhere, to allow various 
 * frameworks to more easily be dropped and loaded in.
 *
 * Also... handling of a list of strings will ALSO be handled outside of 
 * this particular module.
 */
typedef void* edna_string_wtf;
typedef void* edna_stringlist_wtf;

/* Callback to internal data and information of a tag. There is a much 
 * more sophisticated way to do this... but I forgot it.*/
typedef void* edna_internal_data_cb;

/*
 * This is to keep track of really bad code, and have it still able to 
 * work anyways. This again, is to take in information... not determine 
 * if we should report back errors. Even then--errors should be sent to 
 * "webmaster@domain" or any possibly contact able to be gained... not 
 * shown to the user. Possibly with alterable behaviour to report the 
 * errors in some development panel
 */
typedef unsigned int* duplicate_count_pui;

/* Fucking up my enum syntax! HOORAY! Either way... for a callback
 * information stack, it might be useful to include the type.
 */
typedef enum __edna_internals_type_o
{
   comment;
   text;
   tag;
   other_parser;
} edna_internals_type_e;

/*
 * Edna_attribute is a somewhat simply system. We have the key of the 
 * attribute, the value... and a count of duplicate appearances of the 
 * key. This can be used to create an Array of duplicatations of a single
 * key (if it is above 1), to choose the first definition or last to be 
 * used.
 */
typedef struct __edna_attribute_o
{
   edna_memoryhandling_wtf myself;
   edna_string_wtf key;
   edna_string_wtf value;
   duplicate_count_pui count;
} _edna_attribute_s;
typedef _edna_attribute_s* edna_attribute_ps;
typedef _edna_attribute_s* edna_attributes_Aps;

/*
 * For including stuff in the information of the tag itself.
 * it has the memory handling, a handler for basic type, and a 
 * call back for "me" which has the actual items. We couldn't just 
 * have the data in a stack on its own without labelling... as that would
 * be terrible.
 * Comment would be commentary stuff that won't necessary be stripped
 * Text is likely just a really long edna_string_wtf
 * Tag means it is another internal tag
 * Other_parser will require edna_parser_instructions_wtf to be loaded in
 * or some kind of bullshit. We don't have to really care about that right 
 * here anyways.
 */
typedef struct __edna_internal_data_o
{
   edna_memoryhandling_wtf myself;
   edna_internals_type_p type;
   edna_internal_data_cb me;
} _edna_internal_data_s;
typedef _edna_internal_data_s* edna_internal_data_ps;
typedef edna_internal_data_ps* edna_internals_Staps;

/* Information on the current opentag data
 * including the current level of tagged information
 * the attributes and the internals.
 * The tag name will likely be stored under the key of !ELEMENT, !ENTITY,
 * !FIXED or what not... and treated like another attribute of the tag.
 * This isn't standard behaviour of something reading HTML... but then
 * any client that doesn't piss off its usebase don't follow standard 
 * behaviour.
 */
typedef struct __edna_opentag_data_o
{
   edna_memoryhandling_wtf myself;
   signed int level; /* Let's note extra closing tags as imporant */
   edna_attributes_Aps attributes;
   edna_internals_Staps internals;
} _edna_opentag_data_s;
typedef _edna_opentag_data_s* edna_opentag_data_ps;
typedef _edna_opentag_data_s* edna_tag_stack_Staps;

/* Some clues as to how to change what we are handling.
 * We have the opener as a whole string... to make this shit simplistic.
 * We have a LIST of possible closings... because fuck you, that is why.
 */
typedef struct __edna_changemode_o
{
   edna_memoryhandling_wtf myself;
   edna_string_wtf opener;
   edna_stringlist_wtf closers;
} _edna_change_mode_s;
typedef _edna_change_mode_s* edna_specialchar_ps;
typedef _edna_change_mode_s* edna_veryspecial_chars_Aps;

/* Not going to bother with prototype definitions quite yet. Most of this
 * is stupid bullshit that once I've got my little mentally programming 
 * muscles going, I can return, and wonder what fucking paint chips I must 
 * have been eating to write this bullshit down.
 *
 * Or... I might think what I did was awesome... but that almost never 
 * fucking happens.
 *
 * Rest assured... I'm still not at top condition yet, and the code will be
 * getting much tighter in the future.
 *
 * And YES... I plan to have the Memory Manager go through and do a lot 
 * of weird and crazy stuff (that can be changed with various module code)
 * based on what the framework options say and suggest.
 *
 * Still, I wouldn't even call this Alpha stage yet... it is the stage before
 * Alpha... it is "Bullshit"... you know, the stage that gets released on 
 * Steam as an "Alpha" listing... with it just barely still in the Bullshit
 * stage, and maybe might soon be Alpha when it gets marked as "Beta". And 
 * then the release version is what would typically be called "Beta"... 
 * because you can totally just release patches and shit for obviously 
 * terrible code and shit.
 */

edna_veryspecial_chars create(void);

#ifdef __cplusplus
}
#endif
/* So yeah... that was all C Code? */


#endif
