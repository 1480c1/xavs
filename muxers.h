/*****************************************************************************
 * muxer.h: xavs file i/o plugins
 *****************************************************************************
 * Copyright (C) 2009 xavs project
 *
 * Authors: 
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111, USA.
 *****************************************************************************/
#ifndef _XAVS_MUXERS_H_
#define _XAVS_MUXERS_H_

typedef void *hnd_t;

int open_file_yuv( char *psz_filename, hnd_t *p_handle, xavs_param_t *p_param );
int get_frame_total_yuv( hnd_t handle );
int read_frame_yuv( xavs_picture_t *p_pic, hnd_t handle, int i_frame );
int close_file_yuv( hnd_t handle );

int open_file_y4m( char *psz_filename, hnd_t *p_handle, xavs_param_t *p_param );
int get_frame_total_y4m( hnd_t handle );
int read_frame_y4m( xavs_picture_t *p_pic, hnd_t handle, int i_frame );
int close_file_y4m( hnd_t handle );

#ifdef AVIS_INPUT
int open_file_avis( char *psz_filename, hnd_t *p_handle, xavs_param_t *p_param );
int get_frame_total_avis( hnd_t handle );
int read_frame_avis( xavs_picture_t *p_pic, hnd_t handle, int i_frame );
int close_file_avis( hnd_t handle );
#endif

#ifdef HAVE_PTHREAD
int open_file_thread( char *psz_filename, hnd_t *p_handle, xavs_param_t *p_param );
int get_frame_total_thread( hnd_t handle );
int read_frame_thread( xavs_picture_t *p_pic, hnd_t handle, int i_frame );
int close_file_thread( hnd_t handle );
#endif

int open_file_bsf( char *psz_filename, hnd_t *p_handle );
int set_param_bsf( hnd_t handle, xavs_param_t *p_param );
int write_nalu_bsf( hnd_t handle, uint8_t *p_nal, int i_size );
int set_eop_bsf( hnd_t handle,  xavs_picture_t *p_picture );
int close_file_bsf( hnd_t handle );

#ifdef MP4_OUTPUT
int open_file_mp4( char *psz_filename, hnd_t *p_handle );
int set_param_mp4( hnd_t handle, xavs_param_t *p_param );
int write_nalu_mp4( hnd_t handle, uint8_t *p_nal, int i_size );
int set_eop_mp4( hnd_t handle, xavs_picture_t *p_picture );
int close_file_mp4( hnd_t handle );
#endif

int open_file_mkv( char *psz_filename, hnd_t *p_handle );
int set_param_mkv( hnd_t handle, xavs_param_t *p_param );
int write_nalu_mkv( hnd_t handle, uint8_t *p_nal, int i_size );
int set_eop_mkv( hnd_t handle, xavs_picture_t *p_picture );
int close_file_mkv( hnd_t handle );

extern int (*p_open_infile)( char *psz_filename, hnd_t *p_handle, xavs_param_t *p_param );
extern int (*p_get_frame_total)( hnd_t handle );
extern int (*p_read_frame)( xavs_picture_t *p_pic, hnd_t handle, int i_frame );
extern int (*p_close_infile)( hnd_t handle );

#endif
