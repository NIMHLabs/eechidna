/*
 * = HNG Format/Includes/hng.h
 * Author: Katrina Payne
 * Creation Date: June 1st 2014
 *
 * Right... this is being written to try to exercise my programming muscles,
 * but at the same time it does hope that when I get a little bit less rusty
 * to be an important file format for not just eEchidna, but the porn
 * industry in general.
 *
 * The HNG file format started off as a spelling error--a typo if you will.
 * I cannot remember if it was the JPEG or PNG graphic format that I messed
 * up on the spelling... but it resulted in everybody making jokes about 
 * Hentia. Since I cannot remember the original spelling error, I've decided
 * to mutated the PNG and MNG graphic formats to create the HNG format.
 * Pronounced like "hung"... right now, we are not HNG very well... but with
 * a bit of effort we will be so HNG well that it is ridiculous. People will
 * talk about how well HNG truly is... how well HNG is.
 *
 * HNG in its current stage will mix tarball, pgp and fuse capabilities into
 * the format. While its main purpose is to distribute porn securely and 
 * confidently, it would be too limiting, to limit the format to merely 
 * PNG, GIF and/or JPEG graphical data. So many different file formats 
 * can be applied to HNG... but there will be specific formats that HNG
 * will have specific data to append the capabilities of those formats.
 *
 * This isn't even that big of a project. Mixing Tarballs, FUSE, PGP and
 * picture data... but since I am still rusty after way too long without 
 * practice... it might be a bit much for even me
 * == Revisions
 * + 2014-006-01 begun the initial version of this file
 *
 * == TODO
 * ! 2014-006-01 ... do you really have to ask?
 */

#ifndef __eEchidna_HNG_Format_H__
#define __eEchidna_HNG_Format_H__

/* Just guards against C++ */
#ifdef __cplusplus
extern "C"
{
#endif /* We are in C now*/

/* Stuff found in other Echidna modules*/
typedef void* edna_garbage_collection_wtf;
typedef void* edna_string_wtf;
typedef void* edna_time_wtf;
typedef void* edna_checksum_wtf;
typedef void* edna_tagcloud_wtf;
typedef void* edna_memory_transfer_trans;


/* We are going to have package content handling be handled by HNG... because
 * why not? 
 */
typedef enum __enda_giverequire_dat
{
    gives,
    requires,
} edna_giverequire_e;

/*
 * On one level, this means I don't have to specifically define what is 
 * supported by HNG for different module support. On the other this will 
 * work with the Dynamic Memory Management functionality elsewhere in 
 * eEchidna... by allowing the requirements to be nicely packaged in
 * themselves.
 *
 * Keep in mind, the primary use will be porn... not proper program 
 * modulisation, package distrobution and package management. HNG is not 
 * about package management... it is about properly handling porn.
 *
 * Seriously... I hate the effort that goes into organising my porn. 
 * However, if a tool for ogranising porn, can also help eEchidna track
 * and manage its own functionality... well, guess I will have to misuse
 * this porn managing file format.
 */
typedef struct __edna_module_handling_dat
{
   edna_garbage_collector_wtf garbage_collector;
   enda_string_wtf functionality;
   enda_giverequire_e give_require;
   bool satisfied;
} __edna_module_handling_s;
typedef __edna_module_handling_s* edna_module_handling_ps;
typedef edna_module_handling_ps* edna_module_handle_Aps;

/*
 * So the actually data of the file. This will likely be changed and 
 * modified. Right now it is pretty bare bones, and requiring outside
 * modules to give any further handling.
 *
 * The bool "is interlaced" is to suggest that this is just one part
 * of an array of file chunks. Each with their own modules possible to be
 * included. This allows for specific levels of image interlace to be 
 * encrypted under multiple schemes, have different checksum schemes,
 * and be treated as seperate data formats to interact with each other.
 *
 * At the same time, anything that is running well HNG should warn if 
 * different levels of interlacing go in odd directions. At the same 
 * time each chunk will have its chunk number given... and be told
 * how many chunks to expect. At the same time, it will give what
 * it expects the next checksum and prev checksum of the chunks to 
 * look like. If a group of chunks do not appear to exist... it will
 * offer the best of the chunks it can. It will not really look too 
 * hard if chunks appear missing however.
 * */
typedef struct __edna_file_data_dat
{
    edna_garbage_collection_wtf garbage_collection;
    edna_module_handling_Aps handling_requirements;
    enda_string_wtf mimetype;
    edna_string_wtf comments;
    bool is_interlaced;
    unsigned long chunkno, reported_chunks;
    edna_checksum prev_chunkchecksum, next_chunkchecksum;
    unsigned long content_length;
    char *datastreem;
    char *hard_end = "\0\0\0";
    edna_checksum innerchecksum;
} __edna_file_data_s;
typedef __edna_file_data_s* edna_file_data_ps;
typedef edna_file_data_Aps;

/* 
 * Here is the data for the file contents. It has the filename... a best
 * guess as to what the file extension really happens as. Even then... if it
 * is interlaced that information will likely be meaningless. More likely is
 * that people will try to navigate the different files via accessing the tag
 * cloud.
 *
 * A proper fuse handler will allow gallery software, like Gwenview to be able
 * to look at each of these files, and browse the porn collection in HNG via
 * Web 2.0 tags. It also can be used to help story project information in a 
 * way that developers and users can easily handle it and work with it...
 * but only if you are misusing HNG as a package management system, rather 
 * than its main purpose: porn.
 * */
typedef struct __edna_file_stats_dat
{
    edna_garbage_collection_wtf garbage_collection;
    edna_string_wtf filename, file_extension;
    edna_tagcloud_wtf tags;
    edna_time_wtf creation, last_modification, last_view;
    unsigned long revision_counts;
    edna_checksum_wtf current_version;
    unsigned long file_length;
    edna_file_data_Aps file_location;
} __edna_file_stats_s;
typedef __edna_file_stats_s* edna_file_stats_ps;
typedef edna_file_stats_ps* edna_file_stats_Aps;

/* The various function prototypes. Define these elsewhere, naturally */

/* Module handling construction */
edna_module_handle_Aps create(void);

/* Module handling populating */
void push(edna_module_handle_Aps, 
          edna_string_wtf, edna_giverequire_e);
void push(edna_module_handle_Aps, 
          edna_module_handle_Aps);

/* Useful tools */
bool locate(edna_module_handle_Aps, 
            edna_string_wtf);
void satisfy(edna_module_handle_Aps, 
             edna_string_wtf);
void disappiont(enda_module_handle_Aps, 
                edna_string_wtf);
void is_satisfied(edna_module_handle_Aps, 
                  edna_string_wtf);
void remove(edna_module_handle_Aps, 
            edna_string_wtf);
void unrendundant(edna_module_handle_Aps);

/* File stats constructors */
edna_file_stats_ps create(void);
edna_file_stats_Aps create(void);

void filename(edna_file_stats_ps, 
              edna_string_wtf);
edna_string_wtf filename(edna_file_stats_ps);
edna_string_wtf filename(edna_file_stats_ps, 
                         edna_string_wtf);

void guess_extension(edna_file_stats_ps);
void give_extension(edna_file_stats_ps, 
                    edna_string_wtf);
edna_string_wtf give_extension(edna_file_stats_ps, 
                               edna_string_wtf);
edna_string_wtf extension(edna_file_stats_ps);

/* Woohoo! Stuff specifically for our memory management core! Hooray! 
 * This ought to make this shit less confusing, if it is possible*/
edna_memory_transfer_trans tags(edna_file_stats_ps, 
                                edna_memory_transfer_trans);

edna_file_data_ps create(void);
edna_file_data_Aps create(void);


#ifdef __cplusplus
}
#endif /* so if any C++ progs want to use this... we can be polite */

#endif /* The file */
