/*
 * = eEchidna CacheHander:/Header/Cache.h
 * Author: KatrinaTheLamia
 * Project: eEchidna (Mother of all Electronic Monsters)
 * Creation: Novembre 30th 2014
 *
 * So yeah, this isn't being worked on, due to shit going on it my life.
 * Using GitHub code as a blog update! Hooray. Note: change this description
 * file at a later date... or not, this sort of stuff might make this 
 * project notorious.
 *
 * Either way, various software items require some kind of Cache in how 
 * they work and function. Most are just rather simplistic in their nature
 * and others have this weird Cache Magic going on that I'm fairly certain
 * somebody from Hogswarts has got to be maintaining that code. Not that 
 * Hogswarts officially supports the Free Software Foundation, but you'll
 * notice there really isn't that much of a difference between RMS and 
 * Dumbledorf... and Snape DOES look similar to Eric S. Raymond. However, 
 * since we are all Muggles and wizards are clearly not real, neither of 
 * them could be Hogswarts wizards... and my use of muggle was extronious
 * here... so yeah... DO NOT SUSPECT THEM OF THAT!
 *
 * This file, apart from a weird rant at the top that could warm Larry Wall's
 * heart at the top, is mostly just a header file to keep track of data
 * structures and prototypes for how eEchidna can handle caching and what 
 * not. I'll eventually define these prototypes and make them useful... but
 * honestly, this project is referred to as the mother of all electronic 
 * monsters for a good reason.
 *
 * One of those reasons is that it is so fucking over engineered that I 
 * imagine when I get somewhere with it, the source code will be printed 
 * out and hung in the break rooms for various computer science clubs 
 * and programs as a bit of humour to it. With the nerds looking at all 
 * the ridiculously unecessary additions to the software all like, "seriously"
 * or "did a time traveller make this? Do they know John Tidor? Is that 
 * what this is about?" I do not know John Tidor, and have never been 
 * associated with Time Travel, and do not know the fate of RMS (who isn't 
 * Dumbledorf) in the extended universe for Hogswarts nor do I know what 
 * exactly happens to Snape... I mean... RMS (Totally different people--not 
 * the same... REMEMBER THAT).
 *
 * So yeah... long weird rant, in which I rest you assured that Dumbledorf
 * isn't real (and most certainly not RMS), Snape is most certainly not 
 * ESR, I am most certainly not a time travelling immortal lamia and I do 
 * not have any proof that this will be hung in computer science clubs as 
 * a bit of humour not being from the future or anything.
 *
 * == Revisions
 * !+ 2014 Nov 30: File is created
 *
 * == Todo
 * !+ 2014 Nov 30
 * - Define Prototypes
 * - Debug
 * - Documentation
 */

/* Let's get this out of a wet paper bag */
#ifndef __eEchidna_CacheHandler_Cache_H__
#define __eEchidna_CacheHandler_Cache_H__

/* This is all C code from here on in.
 * And yes, I do worry as to what it looks like after the preprocessor 
 * has been ran on the code.
 */
#ifdef __cplusplus
extern "C"
{
#endif

/* Variables with the type _wtf are to be handled with an outside 
 * module. We should not assume we have any clue how it will be handled
 * apart from maybe calling a few safe files to attempt to make use with.
 * Even then, some of this just needs these tagged within the structure 
 * To touch*/
typedef void* edna_memhandler_wtf;
/* This is for memory management and resource tagging*/
typedef void* edna_filehandler_wtf;
/* Filehandler should be able to handle directories, files and archives.
 * In fact, the ability for a Cache to be inside a compressed folder of 
 * some sort would be AWESOME! BOOYAKASHA! */
typedef void* edna_temporal_wtf;
/* The temporal wtf is handled by the time handling part of eEchidna.
 * This will either be a simple throw away thing... or be a bit of software 
 * that has the capabilities to adjust itself based upon current velocity, 
 * positioning in a gravity well, current speed that time is going, possible
 * temporal hijinks, lunar calenders, not currently being located on the 
 * planet Earth... and many other things that will have it so fucking 
 * overengineered it will be a joke in computer science rooms.
 */
typedef void* edna_mimetyping_wtf;
/* What every over engineered program needs. Motherfucking mimetypes being
 * handled. In this case the hope will not to just go by the file extension
 * but to also go by the various inside file identifiers. As well as to 
 * sweep the file for any stenography or hidden files inside it. Even if 
 * maybe it might have been an accident. I wonder how many internet images 
 * have ELF files inside them? They don't have to function... they just have
 * to parse as one. Either way... what the fuck am I fucking smoking? And 
 * why am I not sharing it?
 */

typedef (void*)(edna_midhandl_func)(void*,void*);
/* Screwed up this function pointer definition, I'm certain of it.
 * However... this is for having the midhandler given information on 
 * how to sort out useless information. A filter of sorts.
 */

/* The various purpose a directory can be given.
 * - These files are being transfered to various places, and so to not have
 *   files lost due to transfer issues, they will be cached as part of the 
 *   process
 * - These files are via network traffic. Be it Archie, HTTP, or what not.
 *   In order to make it easier to view them, some of them are to be kept 
 *   locally.
 * - These files are from some form of buffer situation happening. Be 
 *   them from some form of outside storage medium with them being streamed 
 *   somewhere or what not. They are being put into this directory to make 
 *   the process a bit smoother.
 * - Maninthemiddle... a bit more obvious of a naughty usage. However, 
 *   sometimes, it is exactly what the doctor ordered
 * - [REDACTED]
 */
typedef enum __edna_purposes_o 
{
   edna_transfer;
   edna_network;
   edna_buffer;
   edna_maninthemiddle;
   edna_projectwyoming;
} edna_purposes_e;

/*
 * So for the cache file itself, it has memory handler,
 * a location to the file itself. As well, as the creation date 
 * a last modified date and a tracker of what type it is.
 * Logic for the time of it being pulled in, to its last mofidication
 * can be used to determine it is an inferface element, and thus 
 * should be moved into another folder to have it handled as an interface.
 * So we can autocreate applications based on programs web apps.
 */
typedef struct __edna_cache_file_o 
{
   edna_memhandler_wtf myself;
   edna_filehandler_wtf location;
   edna_temporal_wtf creation,
                     last_modified;
   edna_mimetyping_wtf my_type;
} _edna_cache_files_s;
typedef _edna_cache_file_s* edna_cache_file_ps;
typedef _edna_cache_file_s** edna_cache_files_Aps;

/* This is for middlehandling. It has the standard memory handler 
 * hook. As well as a location to place these things. This will 
 * be based upon what mimetype they appear as within the software.
 * The size, shape and weight will be variant based upon what is being
 * watched here. Which will be handled by the function pointer supplied.*/
typedef struct __edna_middlehandler_o
{
   edna_memhandler_wtf myself;
   edna_filehandler_wtf to_place;
   edna_mimetype_wtf what;
   unsigned int size,
                shape,
                weight;
   edna_midhandl_func das_func;
} _edna_middlehandler_s;
typedef _edna_middlehandler_s* edna_middlehandler_ps;
typedef _edna_middlehandler_s** edna_midhandls_Aps;

/* The directory structure and what not.
 * It will have the memory handler, as well as the location of 
 * the cache... and an expiration date given to the stuff located 
 * in there. As well as a date to indicate that is an interface item.
 * Interfaces for quick defined web apps should note that items of it
 * may end up getting updated.
 * It also knows its purpose... and can have man in the middle handlers 
 * loaded for that.
 * Also... the local definitions for this software's usage. This should 
 * really only contain entries in this directory that have been double 
 * checked upon, or at the very least modified to some degree. Stuff 
 * that hasn't been recently loaded, downloaded, uploaded, reloaded and 
 * what not... should not be listed there. They are extronious. I also know 
 * if I don't say that... somebody will take this and load all kinds of shit 
 * into memory needlessly.
 */
typedef struct __edna_cache_directory_o 
{
   edna_memhandler_wtf myself;
   edna_filehandler_wtf location;
   edna_temporal_wtf expiration,
                     interface;
   edna_purposes_e purpose;
   edna_cachefiles_Aps local_defs;
   edna_midhandls_Aps handling;
} _edna_cache_directory_s;
/* To keep the program clean, I suggest we pass it as a _ps to everything
 * This is why the _s version is done as a "hidden" or "private" type
 * even though it is just a polite note to give, eh.*/
typedef *_edna_cache_directory_s edna_cache_directory_ps;
/* Oh right... and an array variation of this. I'll likely write an 
 * intelligent array handler later, that goes through the symbol table 
 * and takes anything with a type that has _A appended, and redoes the 
 * data within it and what not. Fuck yeah symbol tables!
 */
typedef **_edna_cache_directory_s edna_cache_directorylist_Aps;
/* Yes... there was just a comment with the like "Fuck yeah symbol tables!" */

edna_cachefile_ps Create(void);
edna_cachefile_Aps Create(void);
edna_middlehandler_ps Create(void);
edna_midhandlr_Aps Create(void);
edna_cache_directory_ps Create(void);
edna_cache_directorlist_Aps Create(void);

/* eeeh... I work on making more of the prototypes later. Getting fucking 
 * tired and shit. Seriously, I'm still not even back into proper full 
 * action either. Programming muscles need a bit more work still.*/

#ifdef __cplusplus
}
#endif
/* All that them there C code... that will totes fit in after the 
 * preprocessor has been ran
 */

#endif /* The file... do I really need to put the file's define thing
        * here? Are we gonna be that basic about this shit?*/
