/*-----------------------------------------------------------------------------
 /
 / Filename: dice_init.c
 / Author: Valentin Perret
 / Author's email: perret.valentin@gmail.com
 / Description: DICE creates galaxies.
 /
 /	       DICE uses the GNU Scientific Library (GSL). You can
 /	       download the GSL source code from:
 /
 /		http://www.gnu.org/software/gsl
 /
 /	       or replace it with another math library.
 /
 / Copyright Information:
 /
 / Copyright (c) 2014       Valentin Perret
 /
 / This program is free software; you can redistribute it and/or modify
 / it under the terms of the GNU General Public License as published by
 / the Free Software Foundation; either version 2 of the License, or
 / (at your option) any later version.
 /
 / This program is distributed in the hope that it will be useful,
 / but WITHOUT ANY WARRANTY; without even the implied warranty of
 / MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 / GNU General Public License for more details.
 /
 / You should have received a copy of the GNU General Public License
 / along with this program; if not, write to the Free Software
 / Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 /
 / The license is also available at:
 /
 /		http://www.gnu.org/copyleft/gpl.html .
 /
 / Date: October 2014
 /
 *///---------------------------------------------------------------------------

// Include the DICE header
#include "dice.h"

// Allocate component arrays.
int allocate_component_arrays(galaxy *gal) {
	int i;
	
	if (!(gal->comp_profile_name=(char **)malloc(AllVars.MaxCompNumber*sizeof(char *)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_profile_name array\n");
		return -1;
	}
	for (i = 0; i < AllVars.MaxCompNumber; ++i) {
    	if(!(gal->comp_profile_name[i] = (char *)malloc(200))) {
    		fprintf(stderr,"[Error] Unable to allocate comp_profile_name array\n");
			return -1;
    	}
	}
	if (!(gal->comp_mass=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_mass array\n");
		return -1;
	}
	if (!(gal->comp_model=calloc(AllVars.MaxCompNumber,sizeof(int)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_model array\n");
		return -1;
	}
	if (!(gal->comp_npart=calloc(AllVars.MaxCompNumber,sizeof(unsigned long int)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_npart array\n");
		return -1;
	}
	if (!(gal->comp_npart_pot=calloc(AllVars.MaxCompNumber,sizeof(unsigned long int)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_npart_pot array\n");
		return -1;
	}
	if (!(gal->comp_start_part=calloc(AllVars.MaxCompNumber,sizeof(unsigned long int)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_start_part array\n");
		return -1;
	}
	if (!(gal->comp_cutted_mass=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_cutted_mass array\n");
		return -1;
	}
	if (!(gal->comp_scale_length=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_scale_length array\n");
		return -1;
	}
	if (!(gal->comp_scale_height=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_scale_height array\n");
		return -1;
	}
	if (!(gal->comp_cut=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_cut array\n");
		return -1;
	}
	if (!(gal->comp_flat=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_flat array\n");
		return -1;
	}
	if (!(gal->comp_mcmc_step=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_mcmc_step array\n");
		return -1;
	}
	if (!(gal->comp_mcmc_step_hydro=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_mcmc_step array\n");
		return -1;
	}
	if (!(gal->comp_vmax=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_vmax array\n");
		return -1;
	}
	if (!(gal->comp_mass_frac=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_mass_frac array\n");
		return -1;
	}
	if (!(gal->comp_type=calloc(AllVars.MaxCompNumber,sizeof(int)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_type array\n");
		return -1;
	}
	if (!(gal->comp_bool=calloc(AllVars.MaxCompNumber,sizeof(int)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_bool array\n");
		return -1;
	}
	if (!(gal->comp_cut_dens=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_cut_dens array\n");
		return -1;
	}
	if (!(gal->comp_concentration=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_concentration array\n");
		return -1;
	}
	if (!(gal->comp_streaming_fraction=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_streaming_fraction array\n");
		return -1;
	}
	if (!(gal->comp_theta_sph=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_theta_sph array\n");
		return -1;
	}
	if (!(gal->comp_phi_sph=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_phi_sph array\n");
		return -1;
	}
	if (!(gal->comp_metal=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_metal array\n");
		return -1;
	}
	if (!(gal->comp_t_init=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_t_init array\n");
		return -1;
	}
	if (!(gal->comp_u_init=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_u_init array\n");
		return -1;
	}
	if (!(gal->comp_cs_init=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_cs_init array\n");
		return -1;
	}
	if (!(gal->comp_mean_age=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_mean_age array\n");
		return -1;
	}
	if (!(gal->comp_min_age=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_min_age array\n");
		return -1;
	}
	if (!(gal->comp_alpha=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_alpha array\n");
		return -1;
	}
	if (!(gal->comp_disp_ext=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_disp_ext array\n");
		return -1;
	}
	if (!(gal->comp_scale_dens=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_scale_nfw array\n");
		return -1;
	}
	if (!(gal->comp_radius_nfw=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_radius_nfw array\n");
		return -1;
	}
	if (!(gal->comp_Q_lim=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_Q_lim array\n");
		return -1;
	}
	if (!(gal->comp_Q_min=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_Q_min array\n");
		return -1;
	}
	if (!(gal->comp_turb_sigma=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_turb_sigma array\n");
		return -1;
	}
	if (!(gal->comp_turb_scale=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_turb_scale array\n");
		return -1;
	}
	if (!(gal->comp_turb_frac=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_turb_frac array\n");
		return -1;
	}
	if (!(gal->comp_compute_vel=calloc(AllVars.MaxCompNumber,sizeof(int)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_compute_vel array\n");
		return -1;
	}
	if (!(gal->comp_hydro_eq=calloc(AllVars.MaxCompNumber,sizeof(int)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_hydro_eq array\n");
		return -1;
	}
	if (!(gal->comp_hydro_eq_niter=calloc(AllVars.MaxCompNumber,sizeof(int)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_hydro_eq_niter array\n");
		return -1;
	}
	if (!(gal->comp_dens_gauss=calloc(AllVars.MaxCompNumber,sizeof(int)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_dens_gauss array\n");
		return -1;
	}
	if (!(gal->comp_cut_in=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_cut_in array\n");
		return -1;
	}
	if (!(gal->comp_thermal_eq=calloc(AllVars.MaxCompNumber,sizeof(int)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_thermal_eq array\n");
		return -1;
	}
	if (!(gal->comp_part_mass=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_part_mass array\n");
		return -1;
	}
	if (!(gal->comp_jeans_mass_cut=calloc(AllVars.MaxCompNumber,sizeof(int)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_jeans_mass_cut array\n");
		return -1;
	}
	if (!(gal->comp_epicycle=calloc(AllVars.MaxCompNumber,sizeof(int)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_epicycle array\n");
		return -1;
	}
	if (!(gal->comp_flatx=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_flatx array\n");
		return -1;
	}
	if (!(gal->comp_flaty=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_flaty array\n");
		return -1;
	}
	return 0;
}

int allocate_variable_arrays(galaxy *gal) {
	int i,j;	
	// Allocate particle id numbers array
	if (!(gal->id=calloc(gal->ntot_part_pot,sizeof(unsigned long int)))) {
		fprintf(stderr,"[Error] Unable to allocate particle ID numbers.\n");
		return -1;
	}

	// Allocate x coordinates for all the particles.
	if (!(gal->x=calloc(gal->ntot_part_pot,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle x coordinates.\n");
		return -1;
	}
    
	// Allocate y coordinates for all the particles.
	if (!(gal->y=calloc(gal->ntot_part_pot,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle y coordinates.\n");
		return -1;
	}

	// Allocate z coordinates for all the particles.
	if (!(gal->z=calloc(gal->ntot_part_pot,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle z coordinates.\n");
		return -1;
	}
    
	// Allocate cylindrical radius for all the particles.
	if (!(gal->r_cyl=calloc(gal->ntot_part_pot,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle z coordinates.\n");
		return -1;
	}
    
	// Allocate cylindrical azimuthal angle for all the particles.
	if (!(gal->theta_cyl=calloc(gal->ntot_part_pot,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle z coordinates.\n");
		return -1;
	}
    
	// Allocate spherical radius for all the particles.
	if (!(gal->r_sph=calloc(gal->ntot_part_pot,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle z coordinates.\n");
		return -1;
	}
    
	// Allocate spherical azimuthal angle for all the particles.
	if (!(gal->theta_sph=calloc(gal->ntot_part_pot,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle z coordinates.\n");
		return -1;
	}
    
	// Allocate spherical polar angle for all the particles.
	if (!(gal->phi_sph=calloc(gal->ntot_part_pot,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle z coordinates.\n");
		return -1;
	}
    
	// Allocate x velocities for all the particles.
	if (!(gal->vel_x=calloc(gal->ntot_part_pot,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle x coordinates.\n");
		return -1;
	}
    
	// Allocate y velocities for all the particles.
	if (!(gal->vel_y=calloc(gal->ntot_part_pot,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle y coordinates.\n");
		return -1;
	}
    
	// Allocate z velocities for all the particles.
	if (!(gal->vel_z=calloc(gal->ntot_part_pot,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle z coordinates.\n");
		return -1;
	}
    
	// Allocate masses for all the particles.
	if (!(gal->mass=calloc(gal->ntot_part_pot,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle masses.\n");
		return -1;
	}
    
	// Allocate internal energies for all the particles.
	if (!(gal->u=calloc(gal->ntot_part_pot,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle internal energy.\n");
		return -1;
	}
	
	// Allocate metallicity array for particles.
	if (!(gal->metal=calloc(gal->ntot_part_pot,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle metal.\n");
		return -1;
	}
	
	// Allocate age array for all particles.
	if (!(gal->age=calloc(gal->ntot_part_pot,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle age.\n");
		return -1;
	}
	
	// Allocate density array for all particles.
	if (!(gal->rho=calloc(gal->ntot_part_pot,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle age.\n");
		return -1;
	}
    
	// Turn on and allocate the potential grid, starting with x-axis
	gal->potential_defined = 1;
	if (!(gal->potential=calloc(2*gal->ngrid[0],sizeof(double *)))) {
		fprintf(stderr,"[Error] Unable to create potential x axis.\n");
		return -1;
	}
    
	for (i = 0; i < 2*gal->ngrid[1]; ++i) {
		// y-axis
		if (!(gal->potential[i] = calloc(2*gal->ngrid[1],sizeof(double *)))) {
			fprintf(stderr,"[Error] Unable to create potential y axis.\n");
			return -1;
		}
		// z-axis
		for (j = 0; j < 2*gal->ngrid[2]; ++j) {
			if (!(gal->potential[i][j] = calloc(2*gal->ngrid[2],sizeof(double)))) {
				fprintf(stderr,"[Error] Unable to create potential z axis.\n");
				return -1;
			}
		}
	}
	
	if(gal->level_grid_zoom1>gal->level_grid){
		// Turn on and allocate the potential grid, starting with x-axis
		gal->potential_defined = 1;
		if (!(gal->potential_zoom1=calloc(2*gal->ngrid_zoom1[0],sizeof(double *)))) {
			fprintf(stderr,"[Error] Unable to create potential x axis.\n");
			return -1;
		}
    
		for (i = 0; i < 2*gal->ngrid_zoom1[1]; ++i) {
			// y-axis
			if (!(gal->potential_zoom1[i] = calloc(2*gal->ngrid_zoom1[1],sizeof(double *)))) {
				fprintf(stderr,"[Error] Unable to create potential y axis.\n");
				return -1;
			}
			// z-axis
			for (j = 0; j < 2*gal->ngrid_zoom1[2]; ++j) {
				if (!(gal->potential_zoom1[i][j] = calloc(2*gal->ngrid_zoom1[2],sizeof(double)))) {
					fprintf(stderr,"[Error] Unable to create potential z axis.\n");
					return -1;
				}
			}
		}
	}
	
	if(gal->level_grid_zoom2>gal->level_grid_zoom1){
		// Turn on and allocate the potential grid, starting with x-axis
		gal->potential_defined = 1;
		if (!(gal->potential_zoom2=calloc(2*gal->ngrid_zoom2[0],sizeof(double *)))) {
			fprintf(stderr,"[Error] Unable to create potential x axis.\n");
			return -1;
		}
    
		for (i = 0; i < 2*gal->ngrid_zoom2[1]; ++i) {
			// y-axis
			if (!(gal->potential_zoom2[i] = calloc(2*gal->ngrid_zoom2[1],sizeof(double *)))) {
				fprintf(stderr,"[Error] Unable to create potential y axis.\n");
				return -1;
			}
			// z-axis
			for (j = 0; j < 2*gal->ngrid_zoom2[2]; ++j) {
				if (!(gal->potential_zoom2[i][j] = calloc(2*gal->ngrid_zoom2[2],sizeof(double)))) {
					fprintf(stderr,"[Error] Unable to create potential z axis.\n");
					return -1;
				}
			}
		}
	}

	// Allocate the midplane density grid, starting with x-axis
	if (!(gal->midplane_dens=calloc(gal->ngrid_dens[0],sizeof(double *)))) {
		fprintf(stderr,"[Error] Unable to create midplane_dens x axis.\n");
		return -1;
	}
    
	for (i = 0; i < gal->ngrid_dens[1]; ++i) {
		// y-axis
		if (!(gal->midplane_dens[i] = calloc(gal->ngrid_dens[1],sizeof(double *)))) {
			fprintf(stderr,"[Error] Unable to create midplane_dens y axis.\n");
			return -1;
		}
	}
	
	// Allocate index all the threads.
	if (!(gal->index=calloc(AllVars.Nthreads,sizeof(unsigned long int)))) {
		fprintf(stderr,"[Error] Unable to allocate particle index.\n");
		return -1;
	}
	return 0;
}

// Allocate component arrays.
int allocate_component_arrays_stream(stream *st) { 
	int i;
	
	if (!(st->comp_profile_name=(char **)malloc(AllVars.MaxCompNumber*sizeof(char *)))) {
		fprintf(stderr,"[Error] Unable to allocate comp_profile_name array\n");
		return -1;
	}
	for (i = 0; i < AllVars.MaxCompNumber; ++i) {
    	if(!(st->comp_profile_name[i] = (char *)malloc(200))) {
    		fprintf(stderr,"[Error] Unable to allocate comp_profile_name array\n");
			return -1;
    	}
	}
	if (!(st->comp_mass=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle comp_mass array\n");
		return -1;
	}
	if (!(st->comp_dens=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle comp_dens array\n");
		return -1;
	}
	if (!(st->comp_model=calloc(AllVars.MaxCompNumber,sizeof(int)))) {
		fprintf(stderr,"[Error] Unable to allocate particle comp_model array\n");
		return -1;
	}
	if (!(st->comp_npart=calloc(AllVars.MaxCompNumber,sizeof(unsigned long int)))) {
		fprintf(stderr,"[Error] Unable to allocate particle comp_npart array\n");
		return -1;
	}
	if (!(st->comp_start_part=calloc(AllVars.MaxCompNumber,sizeof(unsigned long int)))) {
		fprintf(stderr,"[Error] Unable to allocate particle comp_start_part array\n");
		return -1;
	}
	if (!(st->comp_mcmc_step=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle comp_mcmc_step array\n");
		return -1;
	}
	if (!(st->comp_bool=calloc(AllVars.MaxCompNumber,sizeof(int)))) {
		fprintf(stderr,"[Error] Unable to allocate particle comp_bool array\n");
		return -1;
	}
	if (!(st->comp_theta_sph=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle comp_theta_sph array\n");
		return -1;
	}
	if (!(st->comp_phi_sph=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle comp_phi_sph array\n");
		return -1;
	}
	if (!(st->comp_metal=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle comp_metal array\n");
		return -1;
	}
	if (!(st->comp_t_init=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle comp_t_init array\n");
		return -1;
	}
	if (!(st->comp_u_init=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle comp_u_init array\n");
		return -1;
	}
	if (!(st->comp_cs_init=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle comp_cs_init array\n");
		return -1;
	}
	if (!(st->comp_xc=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle comp_xc array\n");
		return -1;
	}
	if (!(st->comp_yc=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle comp_xc array\n");
		return -1;
	}
	if (!(st->comp_zc=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle comp_xc array\n");
		return -1;
	}
	if (!(st->comp_opening_angle=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle comp_opening_angle array\n");
		return -1;
	}
	if (!(st->comp_length=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle comp_length array\n");
		return -1;
	}
	if (!(st->comp_scale=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle comp_scale array\n");
		return -1;
	}
	if (!(st->comp_turb_sigma=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle comp_turb_sigma array\n");
		return -1;
	}
	if (!(st->comp_turb_scale=calloc(AllVars.MaxCompNumber,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle comp_turb_scale array\n");
		return -1;
	}
	if (!(st->comp_dens_gauss=calloc(AllVars.MaxCompNumber,sizeof(int)))) {
		fprintf(stderr,"[Error] Unable to allocate particle comp_dens_gauss array\n");
		return -1;
	}
	return 0;
}


int allocate_variable_arrays_stream(stream *st) {
	// Allocate particle id numbers array
	if (!(st->id=calloc(st->ntot_part,sizeof(unsigned long int)))) {
		fprintf(stderr,"[Error] Unable to allocate particle ID numbers.\n");
		return -1;
	}

	// Allocate x coordinates for all the particles.
	if (!(st->x=calloc(st->ntot_part,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle x coordinates.\n");
		return -1;
	}
    
	// Allocate y coordinates for all the particles.
	if (!(st->y=calloc(st->ntot_part,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle y coordinates.\n");
		return -1;
	}

	// Allocate z coordinates for all the particles.
	if (!(st->z=calloc(st->ntot_part,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle z coordinates.\n");
		return -1;
	}
    
	// Allocate cylindrical radius for all the particles.
	if (!(st->r_cyl=calloc(st->ntot_part,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle z coordinates.\n");
		return -1;
	}
    
	// Allocate cylindrical azimuthal angle for all the particles.
	if (!(st->theta_cyl=calloc(st->ntot_part,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle z coordinates.\n");
		return -1;
	}
    
	// Allocate spherical radius for all the particles.
	if (!(st->r_sph=calloc(st->ntot_part,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle z coordinates.\n");
		return -1;
	}
    
	// Allocate spherical azimuthal angle for all the particles.
	if (!(st->theta_sph=calloc(st->ntot_part,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle z coordinates.\n");
		return -1;
	}
    
	// Allocate spherical polar angle for all the particles.
	if (!(st->phi_sph=calloc(st->ntot_part,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle z coordinates.\n");
		return -1;
	}
    
	// Allocate x velocities for all the particles.
	if (!(st->vel_x=calloc(st->ntot_part,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle x coordinates.\n");
		return -1;
	}
    
	// Allocate y velocities for all the particles.
	if (!(st->vel_y=calloc(st->ntot_part,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle y coordinates.\n");
		return -1;
	}
    
	// Allocate z velocities for all the particles.
	if (!(st->vel_z=calloc(st->ntot_part,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle z coordinates.\n");
		return -1;
	}
    
	// Allocate masses for all the particles.
	if (!(st->mass=calloc(st->ntot_part,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle masses.\n");
		return -1;
	}
    
	// Allocate internal energies for all the particles.
	if (!(st->u=calloc(st->ntot_part,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle internal energy.\n");
		return -1;
	}
	
	// Allocate metallicity array for particles.
	if (!(st->metal=calloc(st->ntot_part,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle metal.\n");
		return -1;
	}
	
	// Allocate density array for all particles.
	if (!(st->rho=calloc(st->ntot_part,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate particle age.\n");
		return -1;
	}
	return 0;
}



// Create a galaxy
int create_galaxy(galaxy *gal, char *fname, int info) {
	
	unsigned long int i;
	int j,nt;
	int dens_gauss,index_halo;
	// Hubble parameter
	double H;
	// Seed for the random number generator
	long seed;
	double cutted_halo_mass,cutted_disk_mass,cutted_gas_mass,cutted_bulge_mass;
	double halo_npart,disk_npart,gas_npart,bulge_npart;
	double max_gas_radius;
	double baryonic_fraction;
	double BD_fraction,BT_fraction,gas_fraction;
	double effective_mass_factor;
	double rho_crit, delta_c, rho0_nfw, rho_scale_nfw, m_scale_nfw;
	double cut_dens,theta_max_dens;
	
	if(allocate_component_arrays(gal)!=0) {
		fprintf(stderr,"[Error] Allocation of component arrays failed\n");
	}	


	// Parse the galaxy parameters file
	if(parse_galaxy_file(gal,fname) != 0) {
		fprintf(stderr,"[Error] Unable to find the galaxy parameters file\n");
		return -1;
	}

	// Allocate pseudo all the threads.
	if (!(gal->pseudo=calloc(AllVars.Nthreads,sizeof(int)))) {
		fprintf(stderr,"[Error] Unable to allocate pseudo-density switch\n");
		return -1;
	}
	
	// Allocate component selector all the threads.
	if (!(gal->selected_comp=calloc(AllVars.Nthreads,sizeof(int)))) {
		fprintf(stderr,"[Error] Unable to allocate selected_comp array\n");
		return -1;
	}

	// Padding potential grid
	gal->ngrid[0] 			= pow(2,gal->level_grid);
	gal->ngrid[1] 			= pow(2,gal->level_grid);
	gal->ngrid[2] 			= pow(2,gal->level_grid);
	gal->ngrid_dens[0] 		= pow(2,gal->level_grid_dens);
	gal->ngrid_dens[1] 		= pow(2,gal->level_grid_dens);
	
	// Create the random number generator environment
	for(i=0;i<AllVars.Nthreads;i++) gsl_rng_set(r[i],gal->seed);
	printf("/////\tRandom number generators initialised [seed=%d]\n",gal->seed);

	// Set a bunch of constants that defines the galaxy's structure.
	// Set the Hubble parameter from the Friedmann equation
	H = sqrt(pow(AllVars.H0/(1e3*unit_length)*unit_velocity,2.0)*(AllVars.Omega_m*pow(1+gal->redshift,3.0)+AllVars.Omega_k*pow(1+gal->redshift,2.0)+AllVars.Omega_l));
	// Get the Virial velocity from the parser
	// Set the Virial mass
	if((gal->m200==0.)&&(gal->v200>0.)) {
		gal->m200 = pow(gal->v200*unit_velocity,3.0)/(10.0*G*H*unit_mass);
	}
	if(gal->m200>0.) {
		gal->v200 = pow(gal->m200*10.0*G*H*unit_mass,1.0/3.0)/unit_velocity;
	}
	if((gal->m200==0.)&&(gal->v200==0.)) {
			fprintf(stderr,"[Error] Virial parameters not properly defined\n");
			exit(0);
	}
	// Set the Virial radius
	gal->r200 = (gal->v200*unit_velocity)/(10.0*H*kpc);
        
	// Set the size of the cell for the Potential-Mesh (PM) computation
	gal->dx 		= gal->boxsize/((double)gal->ngrid[0]);
	if(gal->level_grid_zoom1>gal->level_grid) {
		gal->dx_zoom1 			= gal->boxsize/pow(2.0,gal->level_grid_zoom1);
		gal->boxsize_zoom1		= ceil(gal->boxsize_zoom1/gal->dx_zoom1)*gal->dx_zoom1;
		gal->ngrid_zoom1[0]		= (int)(gal->boxsize_zoom1/gal->dx_zoom1);
		gal->ngrid_zoom1[1]		= (int)(gal->boxsize_zoom1/gal->dx_zoom1);
		gal->ngrid_zoom1[2]		= (int)(gal->boxsize_zoom1/gal->dx_zoom1);
	}
	if(gal->level_grid_zoom2>gal->level_grid_zoom1) {
		gal->dx_zoom2 			= gal->boxsize/pow(2.0,gal->level_grid_zoom2);
		gal->boxsize_zoom2		= ceil(gal->boxsize_zoom2/gal->dx_zoom2)*gal->dx_zoom2;
		gal->ngrid_zoom2[0]		= (int)(gal->boxsize_zoom2/gal->dx_zoom2);
		gal->ngrid_zoom2[1]		= (int)(gal->boxsize_zoom2/gal->dx_zoom2);
		gal->ngrid_zoom2[2]		= (int)(gal->boxsize_zoom2/gal->dx_zoom2);
	}
	
	allocate_galaxy_storage_variable(gal,10);

	// Initialisations
	gal->ntot_part 			= (unsigned long int)0;
	gal->ntot_part_pot		= (unsigned long int)0;
	gal->ntot_part_stars 	= (unsigned long int)0;
	gal->comp_start_part[0] = (unsigned long int)0;
	gal->total_mass 		= 0.;
	max_gas_radius			= 0.0;
	cutted_halo_mass		= 0.0;
	cutted_disk_mass		= 0.0;
	cutted_gas_mass			= 0.0;
	cutted_bulge_mass		= 0.0;
	gal->num_part[0]		= 0;
	gal->num_part[1]		= 0;
	gal->num_part[2]		= 0;
	gal->num_part[3]		= 0;
	gal->num_part_pot[0]	= 0;
	gal->num_part_pot[1]	= 0;
	gal->num_part_pot[2]	= 0;
	gal->num_part_pot[3]	= 0;
	gal->m_d				= 0.;
	effective_mass_factor	= 0.;
	index_halo				= 0;
	dens_gauss 				= 0;

	for(i=0; i<AllVars.MaxCompNumber; i++){
		// Checking for gaussian fluctuations bool 
		dens_gauss += gal->comp_dens_gauss[i];
		// Rescale the mass fractions
		if(gal->comp_npart[i]>0) effective_mass_factor += gal->comp_mass_frac[i];
		if(gal->comp_type[i]!=1) gal->m_d += gal->comp_mass_frac[i];
		// Find the main halo
		if(gal->comp_type[i]==1 && gal->comp_mass_frac[index_halo]>gal->comp_mass_frac[i]) index_halo = i;
	}
	// Allocate and set the gaussian field grid if necessary
	if(gal->dens_gauss_sigma>0. && gal->dens_gauss_scale>0. && dens_gauss>0){
		gal->ngrid_gauss[0] 		= pow(2,gal->level_grid_dens_gauss);
		gal->ngrid_gauss[1] 		= pow(2,gal->level_grid_dens_gauss);
		gal->ngrid_gauss[2] 		= pow(2,gal->level_grid_dens_gauss);


		if (!(gal->gaussian_field=calloc(2*gal->ngrid_gauss[0],sizeof(double *)))) {
			fprintf(stderr,"[Error] Unable to create turbulence x axis\n");
			return -1;
		}
		for (i = 0; i < 2*gal->ngrid_gauss[1]; ++i) {
			// y-axis
			if (!(gal->gaussian_field[i] = calloc(2*gal->ngrid_gauss[1],sizeof(double *)))) {
				fprintf(stderr,"[Error] Unable to create turbulence y axis\n");
				return -1;
			}
			// z-axis
			for (j = 0; j < 2*gal->ngrid_gauss[2]; ++j) {
				if (!(gal->gaussian_field[i][j] = calloc(2*gal->ngrid_gauss[2],sizeof(double)))) {
					fprintf(stderr,"[Error] Unable to create turbulence z axis\n");
					return -1;
				}
			}
		}		
		for(i=0; i<AllVars.MaxCompNumber; i++){
			if(gal->comp_type[i]==0){
				gal->dx_gauss = 2.1*gal->comp_cut[i]/((double)gal->ngrid_gauss[0]);
			}
		}
		set_galaxy_gaussian_field_grid(gal,gal->dens_gauss_scale);
		printf("/////\tGaussian fluctuations grid initialised [dx=%.3lf kpc]\n",gal->dx_gauss);
		if(gal->dens_gauss_sigma>0.5){
			printf("/////\t[Warning] Gaussian fluctuations may break the axisymmetry hypothesis\n");
		}
		gal->gaussian_field_defined = 1;
	}
	// Turn off GSL errors
	gsl_set_error_handler_off();
	// Do not work with pseudo densities yet
	for(i=0; i<AllVars.Nthreads; i++) gal->pseudo[i] = 0;
	// Rescale the baryon fraction 
	if(AllVars.NormMassFact==1) gal->m_d /= effective_mass_factor;
	// Define disk spin fraction if not specified
	if(gal->j_d==0.) gal->j_d = gal->m_d;
	// Set up component properties
	for(i=0; i<AllVars.MaxCompNumber; i++){
		// Total number of particules
		if(gal->comp_mass_frac[i]==0.) gal->comp_npart[i] = 0;
		if(gal->comp_npart_pot[i]<gal->comp_npart[i]) gal->comp_npart_pot[i] = gal->comp_npart[i];
		if(gal->comp_npart[i]==0) gal->comp_npart_pot[i] = 0;
		// Rescale the mass fractions
		if(AllVars.NormMassFact==1) gal->comp_mass_frac[i] = gal->comp_mass_frac[i]/effective_mass_factor;
		// Set the start index for each component
		if(i>0) gal->comp_start_part[i] = gal->comp_start_part[i-1]+gal->comp_npart_pot[i-1];
		// Computing mass component
		if(gal->comp_mass_frac[i]>0.) gal->comp_mass[i] = gal->m200*gal->comp_mass_frac[i];
		// Set scalelength according to concentration parameter if defined
		if(gal->comp_scale_length[i]==0. && gal->comp_type[i]!=1) gal->comp_scale_length[i] = disk_scale_length_func(gal,gal->comp_concentration[index_halo]);
		if(gal->comp_concentration[i]>0.) {
			gal->comp_scale_length[i] = gal->r200/gal->comp_concentration[i];
		}
		if(gal->comp_concentration[i]==0.&&gal->comp_scale_length[i]>0.) {
			gal->comp_concentration[i] = gal->r200/gal->comp_scale_length[i];
		}
		if(gal->comp_npart[i]>0&&gal->comp_concentration[i]<=0.&&gal->comp_scale_length[i]<=0.) {
			fprintf(stderr,"[Error] Component %d scale not properly defined\n",i+1);
			exit(0);
		}
		// Set the component scale height
		gal->comp_scale_height[i] 	= gal->comp_flat[i]*gal->comp_scale_length[i];
		
		// Reset Q_min to some arbitrary value so it can be calculated later.
		gal->comp_Q_min[i] = 1000.0;

		// We check how many components are present in the galaxy
		// in order to compute masses
		// Booleans to test the presence of a given component
		if(gal->comp_npart[i] > 0) {
			gal->comp_bool[i] = 1;
			gal->n_component++;
		}
		else gal->comp_bool[i] 		= 0;
		
		if(gal->comp_type[i]==0) {
			// Set the gas specific internal energy
			// We assume the gas is in an isothermal state
			gal->comp_u_init[i] = (boltzmann / protonmass) * gal->comp_t_init[i];
			gal->comp_u_init[i] *= unit_mass / unit_energy;
			gal->comp_u_init[i] *= (1.0 / gamma_minus1);
			gal->comp_u_init[i] /= mu_mol;
			// Computing isothermal sound speed
			gal->comp_cs_init[i] 	= sqrt(gamma_minus1*gal->comp_u_init[i]*unit_energy/unit_mass);
			// Removing the turbulent energy support
			gal->comp_u_init[i] 	*= (1.0-gal->comp_turb_frac[i]);
			// Computing the velocity dispersion of the turbulence
			gal->comp_turb_sigma[i] = gal->comp_cs_init[i]*sqrt(gal->comp_turb_frac[i]/(1.0-gal->comp_turb_frac[i]));
		}

		// Computing the mass of the component after cuts
		if(gal->comp_bool[i]) {
			// Case where the final cutted mass is defined by the user
			theta_max_dens				= 0.0;
			gal->comp_scale_dens[i]		= 1.0;
			gal->comp_cut_dens[i] 		= density_functions_pool(gal,gal->comp_cut[i],0.,0.,0,gal->comp_model[i],i);
			if(gal->dens_gauss_sigma>0. && gal->dens_gauss_scale>0. && gal->comp_dens_gauss[i]>0){
				for(j=0; j<1000; j=j+1){
					cut_dens = density_functions_pool(gal,gal->comp_cut[i],(2.0*pi*j/1000.),0.,0,gal->comp_model[i],i);
					if(cut_dens>gal->comp_cut_dens[i]){
						gal->comp_cut_dens[i] = cut_dens;
						theta_max_dens = (2.0*pi*j/1000.);
					}
				}
			}
					
			if(gal->comp_radius_nfw[i]==-1.0) {
				gal->comp_scale_dens[i] 	= gal->comp_mass[i]/cumulative_mass_func(gal,2.0*gal->comp_cut[i],i);
			} else {
				// Case where the final cutted mass is defined by a scaling with respect to a NFW halo density
				m_scale_nfw 				= sqrt(pow(gal->comp_radius_nfw[i]/gal->comp_scale_length[i],2.0));
				rho_crit 					= (gal->m200*gal->comp_mass_frac[i]/200.)*(3.0/(4.0*pi*pow(gal->r200,3.0)));
    			delta_c 					= (200./3.)*pow(gal->comp_concentration[i],3.0)/
    										  (log(1.0+gal->comp_concentration[i])-gal->comp_concentration[i]/(1.0+gal->comp_concentration[i]));
    			rho0_nfw 					= rho_crit*delta_c;
    			rho_scale_nfw 				= rho0_nfw/(m_scale_nfw*pow(1.0+m_scale_nfw,2.0));
    			gal->comp_scale_dens[i] 	= rho_scale_nfw/density_functions_pool(gal,gal->comp_radius_nfw[i],theta_max_dens,0.,0,gal->comp_model[i],i);
			}
		
			gal->comp_cut_dens[i] 		= density_functions_pool(gal,gal->comp_cut[i],theta_max_dens,0.,0,gal->comp_model[i],i);
			gal->comp_cutted_mass[i] 	= cumulative_mass_func(gal,2.0*gal->comp_cut[i],i);
			gal->total_mass				+= gal->comp_cutted_mass[i];
		}

		if(gal->comp_part_mass[i]>0.&&gal->comp_npart[i]>0) gal->comp_npart[i] = (int)round(gal->comp_cutted_mass[i]/(gal->comp_part_mass[i]*solarmass/unit_mass));
		if(gal->comp_npart_pot[i]<gal->comp_npart[i]) gal->comp_npart_pot[i] = gal->comp_npart[i];
		gal->ntot_part_pot 				+= gal->comp_npart_pot[i];
		gal->ntot_part 					+= gal->comp_npart[i];
		// Count stars
		if(gal->comp_type[i]>1) gal->ntot_part_stars += gal->comp_npart[i];

		// Check for disk scalelength values lower or equal to 0
		// If it is the case, compute the disk scalelength according to Mo et al. 1998
		if(gal->comp_type[i]==0 && gal->comp_scale_length[i]>max_gas_radius) max_gas_radius = gal->comp_scale_length[i];
		if(gal->comp_type[i]==1 && gal->lambda>=0) gal->comp_streaming_fraction[i] = f_s_func(gal->comp_concentration[i],gal->lambda);
		// Checking total cutted mass
		if(gal->comp_type[i]==0) cutted_gas_mass 	+= gal->comp_bool[i]*gal->comp_cutted_mass[i];
		if(gal->comp_type[i]==1) cutted_halo_mass 	+= gal->comp_bool[i]*gal->comp_cutted_mass[i];
		if(gal->comp_type[i]==2) cutted_disk_mass 	+= gal->comp_bool[i]*gal->comp_cutted_mass[i];
		if(gal->comp_type[i]==3) cutted_bulge_mass 	+= gal->comp_bool[i]*gal->comp_cutted_mass[i];
		// Checking particle number
		if(gal->comp_type[i]==0) gal->num_part[0] 	+= gal->comp_npart[i];
		if(gal->comp_type[i]==1) gal->num_part[1] 	+= gal->comp_npart[i];
		if(gal->comp_type[i]==2) gal->num_part[2] 	+= gal->comp_npart[i];
		if(gal->comp_type[i]==3) gal->num_part[3] 	+= gal->comp_npart[i];
		if(gal->comp_type[i]==0) gal->num_part_pot[0] 	+= gal->comp_npart_pot[i];
		if(gal->comp_type[i]==1) gal->num_part_pot[1] 	+= gal->comp_npart_pot[i];
		if(gal->comp_type[i]==2) gal->num_part_pot[2] 	+= gal->comp_npart_pot[i];
		if(gal->comp_type[i]==3) gal->num_part_pot[3] 	+= gal->comp_npart_pot[i];
	}
    
    baryonic_fraction 			= (cutted_disk_mass+cutted_gas_mass+cutted_bulge_mass)/gal->m200;
    BT_fraction 				= cutted_bulge_mass/(cutted_bulge_mass+cutted_disk_mass);
    BD_fraction 				= cutted_bulge_mass/cutted_disk_mass;
    gas_fraction				= cutted_gas_mass/(cutted_disk_mass+cutted_gas_mass);
    
	// Print some information to screen.
	if (info != 0) {
		printf("/////\tVirial quantities [z=%5.2lf]\n",gal->redshift);
		printf("/////\t\t- V200 = %6.2lf km/s\n",gal->v200);
		printf("/////\t\t- R200 = %.3lf kpc\n",gal->r200);
		printf("/////\t\t- M200 = %6.2lfe10 Msol\n",gal->m200);
		
		printf("/////\tSystem mass\n");
		printf("/////\t\t- Total mass \t%10.3lfe10 Msol\n",gal->total_mass);
		printf("/////\t\t- Disk mass \t%10.3lfe10 Msol [%4.1lf%%]\n",cutted_disk_mass,100.*cutted_disk_mass/gal->total_mass);
		printf("/////\t\t- Halo mass \t%10.3lfe10 Msol [%4.1lf%%]\n",cutted_halo_mass,100.*cutted_halo_mass/gal->total_mass);
		printf("/////\t\t- Gas mass \t%10.3lfe10 Msol [%4.1lf%%]\n",cutted_gas_mass,100.*cutted_gas_mass/gal->total_mass);
		printf("/////\t\t- Bulge mass \t%10.3lfe10 Msol [%4.1lf%%]\n",cutted_bulge_mass,100.*cutted_bulge_mass/gal->total_mass);
		printf("/////\t\t- Stellar mass \t%10.3lfe10 Msol [%4.1lf%%]\n",(cutted_bulge_mass+cutted_disk_mass),100.*(cutted_bulge_mass+cutted_disk_mass)/gal->total_mass);
		
		printf("/////\tParticle count [final/potential]\n");
		printf("/////\t\t- All         -> %9ld / %9ld\n",gal->ntot_part,gal->ntot_part_pot);
		printf("/////\t\t- Gas         -> %9ld / %9ld\n",gal->num_part[0],gal->num_part_pot[0]);
		printf("/////\t\t- Dark matter -> %9ld / %9ld\n",gal->num_part[1],gal->num_part_pot[1]);
		printf("/////\t\t- Disk        -> %9ld / %9ld\n",gal->num_part[2],gal->num_part_pot[2]);
		printf("/////\t\t- Bulge       -> %9ld / %9ld\n",gal->num_part[3],gal->num_part_pot[3]);
		
		printf("/////\tFractions\n");
		printf("/////\t\t- Baryonic fraction\t%10.3lf\n",baryonic_fraction);
		if(gal->num_part[0]>0&&gal->num_part[2]>0)printf("/////\t\t- Gas fraction\t\t%10.3lf\n",gas_fraction);
		if(gal->num_part[2]>0&&gal->num_part[3]>0)printf("/////\t\t- Bulge Disk fraction\t%10.3lf\n",BD_fraction);
		if(gal->num_part[2]>0&&gal->num_part[3]>0)printf("/////\t\t- Bulge Total fraction\t%10.3lf\n",BT_fraction);
		printf("/////\tPM grids dimensions\n");
		printf("/////\t\t- Gravitational potential \t\t[%4d,%4d,%4d]\n",gal->ngrid[0],gal->ngrid[1],gal->ngrid[2]);
		if(gal->level_grid_zoom1>gal->level_grid) {
			printf("/////\t\t- Gravitational potential zoom 1 \t[%4d,%4d,%4d]\n",gal->ngrid_zoom1[0],gal->ngrid_zoom1[1],gal->ngrid_zoom1[2]);
		}
		if(gal->level_grid_zoom2>gal->level_grid_zoom1) {
			printf("/////\t\t- Gravitational potential zoom 2 \t[%4d,%4d,%4d]\n",gal->ngrid_zoom2[0],gal->ngrid_zoom2[1],gal->ngrid_zoom2[2]);
		}
		for(i=0;i<AllVars.MaxCompNumber;i++) {
			if(gal->comp_hydro_eq[i]) {
				printf("/////\t\t- Midplane gas density \t\t\t[%4d,%4d]\n",(int)pow(2,gal->level_grid_dens),(int)pow(2,gal->level_grid_dens));
				break;
			}
		}
		if(gal->dens_gauss_sigma>0. && gal->dens_gauss_scale>0. && dens_gauss>0) {
			printf("/////\t\t- Gaussian field density \t\t[%4d,%4d,%4d]\n",
			(int)pow(2,gal->level_grid_dens_gauss),(int)pow(2,gal->level_grid_dens_gauss),(int)pow(2,gal->level_grid_dens_gauss));
		}
		for(i=0;i<AllVars.MaxCompNumber;i++) {
			if(gal->comp_type[i]==0 && gal->comp_turb_sigma[i]>0.) {
				printf("/////\t\t- Velocity turbulence \t\t\t[%4d,%4d,%4d]\n",
				(int)pow(2,gal->level_grid_turb),(int)pow(2,gal->level_grid_turb),(int)pow(2,gal->level_grid_turb));
				break;
			}
		}
	}
	fflush(stdout);
	
	if(allocate_variable_arrays(gal)!=0) {
		fprintf(stderr,"Allocation of component arrays failed\n");
	}	
    
    printf("/////\tComponent informations\n");
    for (j=0; j<AllVars.MaxCompNumber; j++) {
    	if(gal->comp_npart[j]>0) {
    		printf("/////\t\t- Component %2d -> %9ld particles / m=%.2e Msol / scale=%6.2lf kpc",j+1,gal->comp_npart[j],(gal->comp_cutted_mass[j]*1.0E10)/(gal->comp_npart_pot[j]),gal->comp_scale_length[j]);
			if(gal->comp_type[j]==1 && gal->lambda>=0) printf(" / lambda=%5.3lf -> f_stream=%5.3lf",gal->lambda,gal->comp_streaming_fraction[j]);
			if(gal->comp_type[j]==0 && gal->comp_hydro_eq[j]==1) printf(" / T_init=%6.2le K / cs=%6.2lf km/s",gal->comp_t_init[j],gal->comp_cs_init[j]/unit_velocity);
			printf("\n");
		}			
		// Filling the arrays of the &galaxy structure
		for (i = gal->comp_start_part[j]; i < gal->comp_start_part[j] + gal->comp_npart_pot[j]; i++) {
			gal->mass[i] 		= gal->comp_cutted_mass[j]/gal->comp_npart_pot[j];
			gal->id[i] 			= i;
			gal->u[i] 			= gal->comp_u_init[j];
			gal->metal[i]		= gal->comp_metal[j];
			// Age is actually stored as time of formation
			// ICs are generated for t=0 therefore formation time is negative
			gal->age[i]			= -((2*gal->comp_mean_age[j]-gal->comp_min_age[j])*gsl_rng_uniform_pos(r[0])+gal->comp_min_age[j]);
		}
	}
	// No problems detected
	return 0;
}


// Create streams
int create_stream(stream *st, char *fname, int info) {
	
	unsigned long int i;
	int j,nt;
	int dens_gauss;
	double base;
	// Seed for the random number generator
	long seed;
	
	if(allocate_component_arrays_stream(st)!=0) {
		fprintf(stderr,"[Error] Allocation of component arrays failed\n");
	}	

	// Parse the galaxy parameters file
	if(parse_stream_file(st,fname) != 0) {
		fprintf(stderr,"[Error] Unable to find the galaxy parameters file\n");
		return -1;
	}
		
	// Allocate component selector all the threads.
	if (!(st->selected_comp=calloc(AllVars.Nthreads,sizeof(int)))) {
		fprintf(stderr,"[Error] Unable to allocate pseudo-density switch\n");
		return -1;
	}

	// Create the random number generator environment
	for(i=0;i<AllVars.Nthreads;i++) gsl_rng_set(r[i],st->seed);
	printf("/////\tRandom number generators initialised [seed=%d]\n",st->seed);


	allocate_stream_storage_variable(st,10);

	st->ntot_part 			= (unsigned long int)0;
	st->comp_start_part[0] 	= (unsigned long int)0;
	st->total_mass			= 0.;
	dens_gauss 				= 0;
	
	for(i=0; i<AllVars.MaxCompNumber; i++){
		// Checking for gaussian fluctuations bool 
		dens_gauss += st->comp_dens_gauss[i];
	}
	// Allocate and set the gaussian field grid if necessary
	if(st->dens_gauss_sigma>0. && st->dens_gauss_scale>0. && dens_gauss>0){
		st->ngrid_gauss[0] 		= pow(2,st->level_grid_dens_gauss);
		st->ngrid_gauss[1] 		= pow(2,st->level_grid_dens_gauss);
		st->ngrid_gauss[2] 		= pow(2,st->level_grid_dens_gauss);


		if (!(st->gaussian_field=calloc(2*st->ngrid_gauss[0],sizeof(double *)))) {
			fprintf(stderr,"[Error] Unable to create turbulence x axis\n");
			return -1;
		}
		
		for (i = 0; i < 2*st->ngrid_gauss[1]; ++i) {
			// y-axis
			if (!(st->gaussian_field[i] = calloc(2*st->ngrid_gauss[1],sizeof(double *)))) {
				fprintf(stderr,"[Error] Unable to create turbulence y axis\n");
				return -1;
			}
			// z-axis
			for (j = 0; j < 2*st->ngrid_gauss[2]; ++j) {
				if (!(st->gaussian_field[i][j] = calloc(2*st->ngrid_gauss[2],sizeof(double)))) {
					fprintf(stderr,"[Error] Unable to create turbulence z axis\n");
					return -1;
				}
			}
		}		
		st->dx_gauss = 0.;
		for(i=0; i<AllVars.MaxCompNumber; i++){
			if(2.1*st->comp_length[i]/((double)st->ngrid_gauss[0])>st->dx_gauss)st->dx_gauss = 2.1*st->comp_length[i]/((double)st->ngrid_gauss[0]);
		}

		set_stream_gaussian_field_grid(st,st->dens_gauss_scale);
		printf("/////\tGaussian fluctuations grid initialised [dx=%.3lf kpc]\n",st->dx_gauss);
		if(st->dens_gauss_sigma>0.5){
			printf("/////\t[Warning] Gaussian fluctuations may break the axisymmetry hypothesis\n");
		}
		st->gaussian_field_defined = 1;
	}
	
	// Set up component properties
	for(i=0; i<AllVars.MaxCompNumber; i++){
	
		// Total number of particules
		st->ntot_part += st->comp_npart[i];
		// Set the start index for each component
		if(i>0) st->comp_start_part[i] = st->comp_start_part[i-1]+st->comp_npart[i-1];

		// We check how many components are present in the galaxy
		// in order to compute masses
		// Booleans to test the presence of a given component
		if(st->comp_npart[i] > 0) {
			st->comp_bool[i] = 1;
			st->n_component++;
		}
		else st->comp_bool[i] 		= 0;

		if(st->comp_bool[i]) {
	    	base	= 2*st->comp_length[i]*atan(pi/180.*st->comp_opening_angle[i]/2.);
			st->comp_mass[i] = cumulative_mass_func_stream(st,base,i);
			st->total_mass += st->comp_bool[i]*st->comp_mass[i];
			// Set the gas specific internal energy
			// We assume the gas is in an isothermal state
			st->comp_u_init[i] = (boltzmann / protonmass) * st->comp_t_init[i];
			st->comp_u_init[i] *= unit_mass / unit_energy;
			st->comp_u_init[i] *= (1.0 / gamma_minus1);
			st->comp_u_init[i] /= mu_mol;
			// Computing isothermal sound speed
			st->comp_cs_init[i] = sqrt(gamma_minus1*st->comp_u_init[i]*unit_energy/unit_mass);
		}
	}
    
	// Print some information to screen
	if (info != 0) {
		printf("/////\tStream properties\n");
		printf("/////\t\t- Gas mass \t%10.3lfe10 Msol\n",st->total_mass);
		printf("/////\t\t- %9ld part\n",st->ntot_part);
	}
	fflush(stdout);

	if(allocate_variable_arrays_stream(st)!=0) {
		fprintf(stderr,"[Error] Allocation of component arrays failed\n");
	}	
    printf("/////\tComponent informations\n");
    for (j=0; j<AllVars.MaxCompNumber; j++) {
    	if(st->comp_npart[j]>0) printf("/////\t\t- Component %2d -> m=%.2e Msol\n",j+1,(st->comp_mass[j]*1.0E10)/(st->comp_npart[j]));
		// Filling the arrays of the &galaxy structure
		for (i = st->comp_start_part[j]; i < st->comp_start_part[j] + st->comp_npart[j]; i++) {
			st->mass[i] 		= st->comp_mass[j]/st->comp_npart[j];
			st->id[i] 			= i;
			st->u[i] 			= st->comp_u_init[j];
			st->rho[i]			= 0.;
			st->metal[i]		= st->comp_metal[j];
		}
	}
	// No problems detected
	return 0;
}

// Use this to allocate the galaxy storage variable on the fly.
void allocate_galaxy_storage_variable(galaxy *gal, int size) {
	int i;

	// Allocate the storage array
	if (!(gal->storage=calloc(size,sizeof(double)))) {
		fprintf(stderr,"[Error] Unable to allocate storage array\n");
		return;
	}
	for (i = 0; i < size; ++i) {
		// y-axis
		if (!(gal->storage[i] = calloc(AllVars.Nthreads,sizeof(double *)))) {
			fprintf(stderr,"[Error] Unable to allocate storage array\n");
			return ;
		}
	}
	
	return;
}

// Use this to allocate the stream storage variable on the fly.
void allocate_stream_storage_variable(stream *st, int size) {
	int i;
	
	// Allocate the storage array
	if (!(st->storage=calloc(size,sizeof(double)))) {
		fprintf(stderr,"Unable to allocate storage array\n");
		return;
	}
	for (i = 0; i < size; ++i) {
		// y-axis
		if (!(st->storage[i] = calloc(AllVars.Nthreads,sizeof(double *)))) {
			fprintf(stderr,"Unable to allocate storage array\n");
			return ;
		}
	}
	return;
}

// Set the positions of the particles in the galaxy to be consistent with the
// various particle distributions. This function uses the Metropolis algorithm
// to allocate particle positions from the distribution functions of each
// galaxy component.
int set_galaxy_coords(galaxy *gal) {
	int i,j;
	
	printf("/////\tComputing coordinates\n");
	fflush(stdout);

	for(i=0; i<AllVars.MaxCompNumber; i++) {
		if(gal->comp_npart[i]>0) {
			printf("/////\t\t- Component %2d [%s]",i+1,gal->comp_profile_name[i]);
			fflush(stdout);
			mcmc_metropolis_hasting(gal,i,gal->comp_model[i]);
		}
	}
	
	for(i=0; i<AllVars.MaxCompNumber; i++) {
		if((gal->comp_hydro_eq[i]==1)&&(gal->comp_npart[i]>0)&&(gal->comp_type[i]==0)) {
			gal->boxsize_dens 	= 2.1*gal->comp_cut[i];
			gal->dx_dens 		= gal->boxsize_dens/((double)gal->ngrid_dens[0]);
			if(set_hydro_equilibrium(gal,i,gal->comp_hydro_eq_niter[i]) != 0) {
				fprintf(stderr,"[Error] Unable to compute azimuthal profile to reach hydro equilibrium\n");
				exit(0);
			}
			gal->comp_cs_init[i] *= (1.0-gal->comp_turb_frac[i]);
		}
	}
	// Be nice to the memory
	return 0;
}

// Set the positions of the particles in the galaxy to be consistent with the
// various particle distributions. This function uses the Metropolis algorithm
// to allocate particle positions from the distribution functions of each
// galaxy component.
int set_stream_coords(stream *st) {
	int i,j;
	
	printf("/////\tComputing coordinates\n");
	fflush(stdout);

	for(i=0; i<AllVars.MaxCompNumber; i++) {
		if(st->comp_npart[i]>0) {
			printf("/////\t\t- Component %2d [%s]",i+1,st->comp_profile_name[i]);
			fflush(stdout);
			mcmc_metropolis_hasting_stream(st,i,st->comp_model[i]);
			position_stream(st,st->comp_xc[i],st->comp_yc[i],st->comp_zc[i],i);
			rotate_stream(st,st->comp_theta_sph[i],st->comp_phi_sph[i],i);
		}
	}
	// Be nice to the memory
	return 0;
}

// Set the velocities of the particles for each component in the galaxy.
// User can choose between cold/hot particles, ie. without velocity dispersion/with velocity dispersion
// This computation is inspired from the work of Springel et al. 2005 & Hernquist 1993
int set_galaxy_velocity(galaxy *gal) {
    
	unsigned long int i,j;
	int status,warning1,warning2,k;
	double v_c, v_r, v_theta, v_z, v_cmax;
	double v2a_r, v2a_theta, v2_theta, v2a_z, va_theta, sigma_theta, vel_x, vel_y, vel_z;
	double vesc[4*gal->ngrid[0]], mass_in_shell;
    double t_min, u_min;
	int nrejected_vr,nrejected_vtheta,nrejected_vz;
	double radius, rmax, interval, save1, save2;

    
	// Warning init
	warning1 = 0;
	warning2 = 0;
    
	// Here we compute the velocity of the particles
	// assuming a Gaussian shaped velocity distribution function.
	// This method is much more realistic, and ensures disk stability
	// against axisymetric perturbations.
	printf("/////\tComputing velocities ");
	fflush(stdout);
	// We fill an array with the value of the escape velocity sampled at radii up to boxsize    
	for(i=0;i<4*gal->ngrid[0];i++) {
		mass_in_shell = 0.;
		for (j=0;j<gal->ntot_part;++j) if(gal->r_sph[j]<(i+1)*gal->dx/4.) mass_in_shell+=gal->mass[j];
		vesc[i] = sqrt(2.0*G*mass_in_shell/((i+1)*gal->dx/4.*kpc));
	}

	#if USE_THREADS == 1
	    int tid = omp_get_thread_num();
	#else
	    int tid = 0;
	#endif
	
	v_cmax 							= 0.;
	gal->index[tid] 				= 0;
	save1 							= gal->z[gal->index[tid]];
	save2 							= gal->theta_cyl[gal->index[tid]];
	gal->z[gal->index[tid]] 		= 0.;
	gal->theta_cyl[gal->index[tid]] = 0.;
	
	rmax 							= gal->boxsize/2.0;
	interval 						= 0.1;
	for (i = 0; i < (int)(rmax/interval); ++i) {
		radius = i*interval;
		v_c = v_c_func(gal,radius);
		if(v_c>v_cmax) v_cmax = v_c;
	}
	printf("[vc_max=%.1lf km/s]\n",v_cmax/unit_velocity);
	gal->z[gal->index[tid]] 		= save1;
	gal->theta_cyl[gal->index[tid]] = save2;
	
	// Setting a minimum thermal energy
	t_min = 100.;
	u_min = (boltzmann / protonmass) * t_min;
	u_min *= unit_mass / unit_energy;
	u_min *= (1.0 / gamma_minus1)/(4./(1.+3.*hydrogen_massfrac));

    // Loop over components
	for(j=0; j<AllVars.MaxCompNumber; j++) {
		nrejected_vr		= 0;
		nrejected_vtheta	= 0;
		nrejected_vz		= 0;
		// Particle velocities.
		if(gal->comp_npart[j]>0&&gal->comp_compute_vel[j]==1) {
			printf("/////\t\t- Component %2d -> setting velocities ",j+1);
			if(gal->comp_thermal_eq[j]) printf("[thermal equilibrium]");
			fflush(stdout);
			#pragma omp parallel for private(v_c, v_r, v_theta, v_z, v2a_r, v2a_z, v2a_theta, v2_theta, va_theta, sigma_theta, vel_x, vel_y, vel_z) shared(j,gal)
			for (i = gal->comp_start_part[j]; i < gal->comp_start_part[j]+gal->comp_npart[j]; ++i) {
				// Get thread ID
				#if USE_THREADS == 1
            		int tid = omp_get_thread_num();
				#else
            		int tid = 0;
				#endif
				gal->index[tid] = i;
				// Specific case of gas particles
				if(gal->comp_type[j]==0) {
					if(gal->comp_hydro_eq[j]==1) gal->pseudo[tid] = 1; 
					v2_theta = v2_theta_gas_func(gal,gal->r_cyl[i],gal->z[i],j);
					// No velocity dispersion is needed because we are dealing with a fluid
					// ie. collisional particles
					v_r 	= 0.;
					v_theta = gal->comp_streaming_fraction[j]*sqrt(v2_theta);
					v_z 	= 0.;
					// If required, overrides the thermal energy to get equilibrium
					if(gal->comp_thermal_eq[j]) {
						v2a_r 		= v2a_1D_func(gal,w[tid],j);
						v_theta 	= gal->comp_streaming_fraction[j]*v_c_func(gal,fabs(gal->r_cyl[i]));
						gal->u[i] 	= v2a_r/(gamma_minus1)*unit_mass/unit_energy;
						// Correct for centrifugal force
						gal->u[i] 	-= v_theta*v_theta*unit_mass/unit_energy;
						if(gal->u[i]<u_min) {
							gal->u[i] = u_min;
							warning2 = 1;
						}
					}
					//Make sure to divide by 1.0E5 to put the velocities in km/s.
					gal->vel_x[i] = (v_r*cos(gal->theta_cyl[i])-v_theta*sin(gal->theta_cyl[i]))/unit_velocity;
					gal->vel_y[i] = (v_r*sin(gal->theta_cyl[i])+v_theta*cos(gal->theta_cyl[i]))/unit_velocity;
					gal->vel_z[i] = v_z/unit_velocity;
				} else {					
					v_c 		= v_c_func(gal,fabs(gal->r_cyl[i]));
					v2a_z 		= v2a_z_func(gal,w[tid],j);
					v2a_r = v2a_z;
					// Enforce Q>Q_min
					if(gal->comp_Q_lim[j]>0) {
						double v2a_z_new = v2a_z_toomre(gal,fabs(gal->r_cyl[i]),v2a_z,j);
						v2a_z = v2a_z_new;
					}
					// The angular velocity dispersion is attenuated radially
					// Because there is a singularity at r=0
					// Using the function: new_disp(scalelength) = disp_softening*disp at the disk scalelength
					if(gal->comp_disp_ext[j]>0. && gal->comp_disp_ext[j]<1.0) {
						double disp_softening = (1.0-exp(-fabs(gal->r_cyl[i])/(-(1.0/log(1.0-gal->comp_disp_ext[j]))*gal->comp_scale_length[j])));
						v2a_r *= disp_softening;
						//v2a_z = v2a_r;
					}
					if(gal->comp_epicycle[j]==1) {
						va_theta = gal->comp_streaming_fraction[j]*v_c;
						sigma_theta = sqrt(sigma2_theta_disk_func(gal,fabs(gal->r_cyl[i]),v2a_z));
					} else {
						va_theta 		= gal->comp_streaming_fraction[j]*v_c;
						v2a_theta 		= v2a_r + pow(v_c,2.0) + v2a_theta_func(gal,gal->r_cyl[i],j);
						// Check if the dispersion is a real or complex number
						if(AllVars.AcceptImaginary==1) {
							sigma_theta = sqrt(fabs(v2a_theta - va_theta*va_theta));
                		} else {
							sigma_theta = (v2a_theta>va_theta*va_theta)?sqrt(v2a_theta-va_theta*va_theta):0.;
                		}
					}
					v_r 	= gsl_ran_gaussian(r[tid],sqrt(v2a_r));
					v_theta = gsl_ran_gaussian(r[tid],sigma_theta)+va_theta;
					v_z 	= gsl_ran_gaussian(r[tid],sqrt(v2a_z));
					// Escape velocity
					//int vesc_index = (int)(gal->r_sph[i]/(gal->space[0]/4.));
            	
					// Let's ensure that the particle velocity is lower than gal->disk_vmax times the escape velocity
					int ct = 0;
					
					while(fabs(v_r) > gal->comp_vmax[j]*v_cmax) {
						if(ct >= AllVars.GaussianRejectIter) {
							v_r = 2.0*gal->comp_vmax[j]*v_cmax*(gsl_rng_uniform_pos(r[tid])-0.5);
							break;
						}
						v_r = gsl_ran_gaussian(r[tid],sqrt(v2a_r));
						if(ct==0) nrejected_vr+=1;
						ct++;
					}
					ct = 0;
					while(fabs(v_theta-va_theta) > gal->comp_vmax[j]*v_cmax) {
						if(ct >= AllVars.GaussianRejectIter) {
							v_theta = 2.0*gal->comp_vmax[j]*v_cmax*(gsl_rng_uniform_pos(r[tid])-0.5)+va_theta;
							break;
						}
						v_theta = gsl_ran_gaussian(r[tid],sigma_theta)+va_theta;
						if(ct==0) nrejected_vtheta+=1;
						ct++;
					}
					ct = 0;
					while(fabs(v_z) > gal->comp_vmax[j]*v_cmax) {
						if(ct >= AllVars.GaussianRejectIter) {
							v_z = 2.0*gal->comp_vmax[j]*v_cmax*(gsl_rng_uniform_pos(r[tid])-0.5);
							break;
						}
						v_z = gsl_ran_gaussian(r[tid],sqrt(v2a_z));
						if(ct==0) nrejected_vz+=1;
						ct++;
					}
					
					vel_x 	= (v_r*cos(gal->theta_cyl[i])-v_theta*sin(gal->theta_cyl[i]))/unit_velocity;
					vel_y 	= (v_r*sin(gal->theta_cyl[i])+v_theta*cos(gal->theta_cyl[i]))/unit_velocity;
					vel_z 	= v_z/unit_velocity;
            	
					gal->vel_x[i] = vel_x;
					gal->vel_y[i] = vel_y;
					gal->vel_z[i] = vel_z;
				}
			}
			#pragma omp barrier
			if(gal->comp_Q_lim[j]>0.) printf("[Q_min=%.2lf]",gal->comp_Q_min[j]);
			if(nrejected_vr>1e-3||nrejected_vtheta>1e-3||nrejected_vz>1e-3) printf("[reject_vr=%.1lf%%][reject_vtheta=%.1lf%%][reject_vz=%.1lf%%]",
				100.*nrejected_vr/(double)gal->comp_npart[j],
				100.*nrejected_vtheta/(double)gal->comp_npart[j],
				100.*nrejected_vz/(double)gal->comp_npart[j]);
			printf("\n");
		}
		if(warning2) printf("/////\t\t[Warning] Gaseous halo unstable -> Lower streaming_fraction%d\n",j+1);
		warning2 = 0;
	}

	if(warning1) printf("/////\t\t[Warning] Potential derivative unstable -> Increase particule number\n");
    
    char buffer[MAXLEN_FILENAME];
	double maxrad, maxrad_gas;

	maxrad 		= 0.;
	maxrad_gas 	= 0.;
	for(j=0; j<AllVars.MaxCompNumber; j++) {
		if(gal->comp_cut[j]>maxrad) maxrad = gal->comp_cut[j];
		if(gal->comp_cut[j]>maxrad_gas && gal->comp_type[j]==0) maxrad_gas = gal->comp_cut[j];
	}

    // Writing rotation curve to ascii file
    if(AllVars.OutputRc==1){
		strcpy(buffer,AllVars.GalaxyFiles[AllVars.CurrentGalaxy]);
		printf("/////\tWriting rotation curve \t\t\t[%s.rc]\n",AllVars.GalaxyFiles[AllVars.CurrentGalaxy]);
		write_galaxy_rotation_curve(gal,maxrad,strcat(buffer,".rc"),0.01);
	}
    // Writing gas rotation curve to ascii file
    if(AllVars.OutputGasRc==1){
		strcpy(buffer,AllVars.GalaxyFiles[AllVars.CurrentGalaxy]);
		printf("/////\tWriting gas rotation curve \t\t[%s.gasrc]\n",AllVars.GalaxyFiles[AllVars.CurrentGalaxy]);
		write_galaxy_gas_rotation_curve(gal,maxrad_gas,strcat(buffer,".gasrc"),0.01);
	}
	// Writing potential curve to ascii file
    if(AllVars.OutputPot==1){
		strcpy(buffer,AllVars.GalaxyFiles[AllVars.CurrentGalaxy]);
		printf("/////\tWriting potential curve \t\t[%s.pot]\n",AllVars.GalaxyFiles[AllVars.CurrentGalaxy]);
		write_galaxy_potential_curve(gal,maxrad,strcat(buffer,".pot"),0.01);
	}
	// Writing gas density curve to ascii file
    if(AllVars.OutputRho>0){
    	gal->selected_comp[0] = AllVars.OutputRho-1;
		strcpy(buffer,AllVars.GalaxyFiles[AllVars.CurrentGalaxy]);
		printf("/////\tWriting density curve \t\t\t[%s.rho]\n",AllVars.GalaxyFiles[AllVars.CurrentGalaxy]);
		write_galaxy_density_curve(gal,1.1*gal->comp_cut[gal->selected_comp[0]],strcat(buffer,".rho"),0.01);
	}
	// Writing gas density curve to ascii file
    if(AllVars.OutputToomre>0){
    	gal->selected_comp[0] = AllVars.OutputToomre-1;
		strcpy(buffer,AllVars.GalaxyFiles[AllVars.CurrentGalaxy]);
		printf("/////\tWriting Toomre criterion curve \t\t[%s.toomre]\n",AllVars.GalaxyFiles[AllVars.CurrentGalaxy]);
		write_galaxy_toomre_curve(gal,1.1*gal->comp_cut[gal->selected_comp[0]],strcat(buffer,".toomre"),0.01);
	}
	// Writing dispersion curves to ascii file
    if(AllVars.OutputSigma>0){
    	gal->selected_comp[0] = AllVars.OutputSigma-1;
		strcpy(buffer,AllVars.GalaxyFiles[AllVars.CurrentGalaxy]);
		printf("/////\tWriting vz dispersion curve \t\t[%s.sigma_z]\n",AllVars.GalaxyFiles[AllVars.CurrentGalaxy]);
		write_galaxy_sigma_z_curve(gal,1.1*gal->comp_cut[gal->selected_comp[0]],strcat(buffer,".sigma_z"),0.01);
		
		strcpy(buffer,AllVars.GalaxyFiles[AllVars.CurrentGalaxy]);
		printf("/////\tWriting vtheta dispersion curve \t[%s.sigma_theta]\n",AllVars.GalaxyFiles[AllVars.CurrentGalaxy]);
		write_galaxy_sigma_theta_curve(gal,1.1*gal->comp_cut[gal->selected_comp[0]],strcat(buffer,".sigma_theta"),0.01);
	}
	// Be nice to memory
	free(gal->storage);
    // Loop over components
    printf("/////\t Computing turbulence\n");
	for(k=0; k<AllVars.MaxCompNumber; k++) {
    	if(gal->comp_type[k]==0 && gal->comp_turb_sigma[k]>0. && gal->comp_npart[k]>0) {
    	
    		// Deallocate potential grid to save some memory for the next computation
    		if(gal->potential_defined) {
    			for (i = 0; i < 2*gal->ngrid[1]; i++){
					for (j = 0; j < 2*gal->ngrid[2]; j++){
						free(gal->potential[i][j]);
					}
					free(gal->potential[i]);
				}
				free(gal->potential);
				gal->potential_defined = 0;
			}
			
			// Deallocate the gaussian field grid to be really nice to the memory.
			if(gal->gaussian_field_defined){
				for (i = 0; i < 2*gal->ngrid_gauss[1]; i++){
					for (j = 0; j < 2*gal->ngrid_gauss[2]; j++){
						free(gal->gaussian_field[i][j]);
					}
					free(gal->gaussian_field[i]);
				}
				free(gal->gaussian_field);
				gal->gaussian_field_defined = 0;
    		}
    		
    	    gal->ngrid_gauss[0] 	= pow(2,gal->level_grid_turb);
    	    gal->ngrid_gauss[1] 	= pow(2,gal->level_grid_turb);
    	    gal->ngrid_gauss[2] 	= pow(2,gal->level_grid_turb);
			
    		if (!(gal->gaussian_field=calloc(2*gal->ngrid_gauss[0],sizeof(double *)))) {
				fprintf(stderr,"[Error] Unable to create turbulence x axis\n");
				return -1;
			}
    
			for (i = 0; i < 2*gal->ngrid_gauss[1]; ++i) {
				// y-axis
				if (!(gal->gaussian_field[i] = calloc(2*gal->ngrid_gauss[1],sizeof(double *)))) {
					fprintf(stderr,"[Error] Unable to create turbulence y axis\n");
					return -1;
				}
				// z-axis
				for (j = 0; j < 2*gal->ngrid_gauss[2]; ++j) {
					if (!(gal->gaussian_field[i][j] = calloc(2*gal->ngrid_gauss[2],sizeof(double)))) {
						fprintf(stderr,"[Error] Unable to create turbulence z axis\n");
						return -1;
					}
				}
			}

    		gal->dx_gauss = 2.1*gal->comp_cut[k]/((double)gal->ngrid_gauss[0]);

   			printf("/////\t\t- Component %2d -> setting turbulence [sigma=%.2lf km/s][scale=%.2lf kpc][grid scale=%.3lf kpc]\n",k+1,gal->comp_turb_sigma[k]/unit_velocity,gal->comp_turb_scale[k],gal->dx_gauss);
    		set_galaxy_gaussian_field_grid(gal,gal->comp_turb_scale[k]);
			for (i = gal->comp_start_part[k]; i < gal->comp_start_part[k]+gal->comp_npart[k]; ++i) {
				gal->vel_x[i] += galaxy_gaussian_field_func(gal,gal->x[i],gal->y[i],gal->z[i])*gal->comp_turb_sigma[k]/unit_velocity;
			}
    		set_galaxy_gaussian_field_grid(gal,gal->comp_turb_scale[k]);
			for (i = gal->comp_start_part[k]; i < gal->comp_start_part[k]+gal->comp_npart[k]; ++i) {
				gal->vel_y[i] += galaxy_gaussian_field_func(gal,gal->x[i],gal->y[i],gal->z[i])*gal->comp_turb_sigma[k]/unit_velocity;
			}
    		set_galaxy_gaussian_field_grid(gal,gal->comp_turb_scale[k]);
			for (i = gal->comp_start_part[k]; i < gal->comp_start_part[k]+gal->comp_npart[k]; ++i) {
				gal->vel_z[i] += galaxy_gaussian_field_func(gal,gal->x[i],gal->y[i],gal->z[i])*gal->comp_turb_sigma[k]/unit_velocity;
			}
			// Deallocate the turbulence grid to be really nice to the memory.
			for (i = 0; i < 2*gal->ngrid_gauss[1]; i++){
				for (j = 0; j < 2*gal->ngrid_gauss[2]; j++){
					free(gal->gaussian_field[i][j]);
				}
				free(gal->gaussian_field[i]);
			}
			free(gal->gaussian_field);
		}
    }
    // Loop over components
	for(k=0; k<AllVars.MaxCompNumber; k++) {
    	rotate_component(gal,gal->comp_theta_sph[k],gal->comp_phi_sph[k],k);
	}
    
	return 0;
}


// Set the velocities of the particles for each component in the stream.
// User can choose between cold/hot particles, ie. without velocity dispersion/with velocity dispersion
// This computation is inspired from the work of Springel et al. 2005 & Hernquist 1993
int set_stream_velocity(stream *st) {
    
	unsigned long int i,j;
	int status,warning,k;
	double v_c, v_theta, v_r, v_z;
	double sigma_theta;
	double v2a_r, v2a_theta, v2_theta, va_theta, vel_x, vel_y, vel_z, streaming_fraction;
    
	// Here we compute the velocity of the particles
	// assuming a Gaussian shaped velocity distribution function.
	// This method is much more realistic, and ensures disk stability
	// against axisymetric perturbations.
	printf("/////\tSetting velocities\n");
	fflush(stdout);

    // Loop over components
	for(j=0; j<AllVars.MaxCompNumber; j++) {
		// Particle velocities.
		if(st->comp_npart[j]>0) {
			printf("/////\t\t-Setting component %d particles velocities\n",j+1);
			fflush(stdout);
			for (i = st->comp_start_part[j]; i < st->comp_start_part[j]+st->comp_npart[j]; ++i) {
				//Make sure to divide by 1.0E5 to put the velocities in km/s.
				st->vel_x[i] = gsl_ran_gaussian(r[0],st->comp_turb_sigma[j]);
				st->vel_y[i] = gsl_ran_gaussian(r[0],st->comp_turb_sigma[j]);
				st->vel_z[i] = gsl_ran_gaussian(r[0],st->comp_turb_sigma[j]);
			}
		}
	}

	printf("/////\tSetting gas turbulent velocities\n");
    // Loop over components
	for(k=0; k<AllVars.MaxCompNumber; k++) {
    	if(st->comp_turb_sigma[k]>0.) {

			// Deallocate the gaussian field grid to be really nice to the memory.
			if(st->gaussian_field_defined){
				for (i = 0; i < 2*st->ngrid_gauss[1]; i++){
					for (j = 0; j < 2*st->ngrid_gauss[2]; j++){
						free(st->gaussian_field[i][j]);
					}
					free(st->gaussian_field[i]);
				}
				free(st->gaussian_field);
				st->gaussian_field_defined = 0;
    		}
    	
    		st->ngrid_gauss[0] 		= pow(2,st->level_grid_turb);
    		st->ngrid_gauss[1] 		= pow(2,st->level_grid_turb);
    		st->ngrid_gauss[2] 		= pow(2,st->level_grid_turb);
    	
    		if (!(st->gaussian_field=calloc(2*st->ngrid_gauss[0],sizeof(double *)))) {
				fprintf(stderr,"Unable to create turbulence x axis.\n");
				return -1;
			}
    
			for (i = 0; i < 2*st->ngrid_gauss[1]; ++i) {
				// y-axis
				if (!(st->gaussian_field[i] = calloc(2*st->ngrid_gauss[1],sizeof(double *)))) {
					fprintf(stderr,"Unable to create turbulence y axis.\n");
					return -1;
				}
				// z-axis
				for (j = 0; j < 2*st->ngrid_gauss[2]; ++j) {
					if (!(st->gaussian_field[i][j] = calloc(2*st->ngrid_gauss[2],sizeof(double)))) {
						fprintf(stderr,"Unable to create turbulence z axis.\n");
						return -1;
					}
				}
			}

    		st->dx_gauss = 2.1*st->comp_length[k]/((double)st->ngrid_gauss[0]);

			printf("/////\t\t-Setting component %d turbulence [sigma=%.2lf km/s][scale=%.2lf kpc][grid element=%.3lf kpc]\n",k,st->comp_turb_sigma[k],st->comp_turb_scale[k],st->dx_gauss);
    		set_stream_gaussian_field_grid(st,st->comp_turb_sigma[k]);
			for (i = st->comp_start_part[k]; i < st->comp_start_part[k]+st->comp_npart[k]; ++i) {
				st->vel_x[i] += stream_gaussian_field_func(st,st->x[i],st->y[i],st->z[i])*st->comp_turb_sigma[k];
			}
    		set_stream_gaussian_field_grid(st,st->comp_turb_sigma[k]);
			for (i = st->comp_start_part[k]; i < st->comp_start_part[k]+st->comp_npart[k]; ++i) {
				st->vel_y[i] += stream_gaussian_field_func(st,st->x[i],st->y[i],st->z[i])*st->comp_turb_sigma[k];
			}
    		set_stream_gaussian_field_grid(st,st->comp_turb_sigma[k]);
			for (i = st->comp_start_part[k]; i < st->comp_start_part[k]+st->comp_npart[k]; ++i) {
				st->vel_z[i] += stream_gaussian_field_func(st,st->x[i],st->y[i],st->z[i])*st->comp_turb_sigma[k];
			}
			// Deallocate the turbulence grid to be really nice to the memory.
			for (i = 0; i < 2*st->ngrid_gauss[1]; i++){
				for (j = 0; j < 2*st->ngrid_gauss[2]; j++){
					free(st->gaussian_field[i][j]);
				}
				free(st->gaussian_field[i]);
			}
			free(st->gaussian_field);
		}
    }

	return 0;
}


// Be kind to the memory, destroy a galaxy...
void destroy_galaxy(galaxy *gal, int info) {
	
	int i,j;
	
	if (info != 0) printf("/////Destroying galaxy...");
	// Deallocate the potential grid to be really nice to the memory.
	if(gal->potential_defined == 1){
		for (i = 0; i < 2*gal->ngrid[1]; i++){
			for (j = 0; j < 2*gal->ngrid[2]; j++){
				free(gal->potential[i][j]);
			}
			free(gal->potential[i]);
		}
		free(gal->potential);
	}
	// Deallocate all the small parts of the galaxy to be nice to the memory.
	free(gal->id);
	free(gal->x);
	free(gal->y);
	free(gal->z);
	free(gal->mass);
	free(gal->vel_x);
	free(gal->vel_y);
	free(gal->vel_z);
	free(gal->u);
	free(gal->rho);
	free(gal->age);
	free(gal->metal);
	if (info != 0) printf("///// All memory unallocated.\n");
	return;
}


// Destroy a system of galaxies.
void destroy_galaxy_system(galaxy *gal, int info) {
	
	if (info != 0) printf("/////Destroying galaxy system...");
	free(gal->id);
	free(gal->x);
	free(gal->y);
	free(gal->z);
	free(gal->mass);
	free(gal->vel_x);
	free(gal->vel_y);
	free(gal->vel_z);
	free(gal->u);
	free(gal->rho);
	free(gal->age);
	free(gal->metal);
	if (info != 0) printf("///// All memory unallocated.\n");
    return;
}


// This function intend to perform rotation onto a galaxy, in order to test
// different combination of ICs for galaxy colision simulations.
// The orientation angles should be specified in degrees.
int rotate_galaxy(galaxy *gal, double alpha, double delta) {
	
	unsigned long int i;
	double x_temp, y_temp, z_temp;
	double vx_temp, vy_temp, vz_temp;
	// Alpha is the spin angle
	// Delta is the inclination of the disk compare to the XY plane
	alpha = alpha*pi/180.;
	delta = delta*pi/180.;
	for(i = 0; i<gal->ntot_part_pot; ++i) {
		//Rotation around Y axis
        x_temp			= cos(delta)*gal->x[i]+sin(delta)*gal->z[i];
        z_temp			= cos(delta)*gal->z[i]-sin(delta)*gal->x[i];
        vx_temp			= cos(delta)*gal->vel_x[i]+sin(delta)*gal->vel_z[i];
        vz_temp			= cos(delta)*gal->vel_z[i]-sin(delta)*gal->vel_x[i];
		gal->x[i] 		= x_temp;
        gal->z[i] 		= z_temp;
		gal->vel_x[i] 	= vx_temp;
		gal->vel_z[i] 	= vz_temp;
        //Rotation around Z axis
        x_temp			= cos(alpha)*gal->x[i]+sin(alpha)*gal->y[i];
        y_temp			= cos(alpha)*gal->y[i]-sin(alpha)*gal->x[i];
        vx_temp			= cos(alpha)*gal->vel_x[i]+sin(alpha)*gal->vel_y[i];
        vy_temp			= cos(alpha)*gal->vel_y[i]-sin(alpha)*gal->vel_x[i];
        gal->x[i] 		= x_temp;
        gal->y[i] 		= y_temp;
		gal->vel_x[i] 	= vx_temp;
		gal->vel_y[i] 	= vy_temp;
	}
	return 0;
}


// This function intend to perform rotation onto a galaxy, in order to test
// different combination of ICs for galaxy colision simulations.
// The orientation angles should be specified in degrees.
int rotate_component(galaxy *gal, double alpha, double delta, int component) {
	
	unsigned long int i;
	double x_temp, y_temp, z_temp;
	double vx_temp, vy_temp, vz_temp;
	// Alpha is the spin angle
	// Delta is the inclination of the disk compare to the XY plane
	alpha = alpha*pi/180.;
	delta = delta*pi/180.;
	for(i = gal->comp_start_part[component]; i<gal->comp_start_part[component]+gal->comp_npart_pot[component]; ++i) {
		//Rotation around Y axis
        x_temp			= cos(delta)*gal->x[i]+sin(delta)*gal->z[i];
        z_temp			= cos(delta)*gal->z[i]-sin(delta)*gal->x[i];
        vx_temp			= cos(delta)*gal->vel_x[i]+sin(delta)*gal->vel_z[i];
        vz_temp			= cos(delta)*gal->vel_z[i]-sin(delta)*gal->vel_x[i];
		gal->x[i] 		= x_temp;
        gal->z[i] 		= z_temp;
		gal->vel_x[i] 	= vx_temp;
		gal->vel_z[i] 	= vz_temp;
        //Rotation around Z axis
        x_temp			= cos(alpha)*gal->x[i]+sin(alpha)*gal->y[i];
        y_temp			= cos(alpha)*gal->y[i]-sin(alpha)*gal->x[i];
        vx_temp			= cos(alpha)*gal->vel_x[i]+sin(alpha)*gal->vel_y[i];
        vy_temp			= cos(alpha)*gal->vel_y[i]-sin(alpha)*gal->vel_x[i];
        gal->x[i] 		= x_temp;
        gal->y[i] 		= y_temp;
		gal->vel_x[i] 	= vx_temp;
		gal->vel_y[i] 	= vy_temp;
	}
	return 0;
}

// This function intend to perform rotation onto a galaxy, in order to test
// different combination of ICs for galaxy colision simulations.
// The orientation angles should be specified in degrees.
int rotate_stream(stream *st, double alpha, double delta, int component) {
	
	unsigned long int i;
	double x_temp, y_temp, z_temp;
	double vx_temp, vy_temp, vz_temp;
	// Alpha is the spin angle
	// Delta is the inclination of the disk compare to the XY plane
	alpha = alpha*pi/180.;
	delta = delta*pi/180.;
	for(i = st->comp_start_part[component]; i<st->comp_start_part[component]+st->comp_npart[component]; ++i) {
		//Rotation around Y axis
        x_temp			= cos(delta)*st->x[i]+sin(delta)*st->z[i];
        z_temp			= cos(delta)*st->z[i]-sin(delta)*st->x[i];
        vx_temp			= cos(delta)*st->vel_x[i]+sin(delta)*st->vel_z[i];
        vz_temp			= cos(delta)*st->vel_z[i]-sin(delta)*st->vel_x[i];
		st->x[i] 		= x_temp;
        st->z[i] 		= z_temp;
		st->vel_x[i] 	= vx_temp;
		st->vel_z[i] 	= vz_temp;
        //Rotation around Z axis
        x_temp			= cos(alpha)*st->x[i]+sin(alpha)*st->y[i];
        y_temp			= cos(alpha)*st->y[i]-sin(alpha)*st->x[i];
        vx_temp			= cos(alpha)*st->vel_x[i]+sin(alpha)*st->vel_y[i];
        vy_temp			= cos(alpha)*st->vel_y[i]-sin(alpha)*st->vel_x[i];
        st->x[i] 		= x_temp;
        st->y[i] 		= y_temp;
		st->vel_x[i] 	= vx_temp;
		st->vel_y[i] 	= vy_temp;
	}
	return 0;
}

// This function intend to perform rotation onto a galaxy, in order to test
// different combination of ICs for galaxy colision simulations.
// The orientation angles should be specified in degrees.
int position_stream(stream *st, double xc, double yc, double zc, int component) {
	
	unsigned long int i;

	for(i = st->comp_start_part[component]; i<st->comp_start_part[component]+st->comp_npart[component]; ++i) {
		st->x[i] 		+= xc;
		st->y[i] 		+= yc;
        st->z[i] 		+= zc;

	}
	return 0;
}


// This function intend to setup the gloabal postion velocity vectors of a galaxy, in order to test
// different combination of ICs for galaxy colision simulations.
int set_galaxy_trajectory(galaxy *gal) {
	unsigned long int i;
    
	for(i = 0; i<gal->ntot_part_pot; ++i) {
		gal->x[i] 		+= gal->xc;
		gal->y[i] 		+= gal->yc;
        gal->z[i] 		+= gal->zc;
		gal->vel_x[i] 	+= gal->vel_xc;
		gal->vel_y[i] 	+= gal->vel_yc;
		gal->vel_z[i] 	+= gal->vel_zc;
	}
	return 0;
}

// In order to perform a galaxy collision, it is necessary to combine
// two galaxies into one set of orbiting galaxies. The orbits should
// be defined by a user-defined orbit or the set_orbit_parabolic()
// function and the following function should be called to combine
// the galaxies into one object.
//
// It is necessary to allocate the different parts of the memory here
// because this galactic system does not have quantities like halo
// or disk scale lengths. These are quantities in the parent galaxy,
// not the galaxy-orbit-galaxy combination.
int create_galaxy_system(galaxy *gal_1, galaxy *gal_2, galaxy *gal_3) {
	unsigned long int i,a;
	int j,k;

	if(allocate_component_arrays(gal_3)!=0) {
		fprintf(stderr,"Allocation of component arrays failed\n");
	}

	// Create the galaxy system first!
	j=0;
	for(k=0;k<AllVars.MaxCompNumber;k++) {
		if(gal_2->comp_npart[k]>0) {
			gal_3->comp_npart[j]				= gal_2->comp_npart[k];
			gal_3->comp_npart_pot[j]			= gal_2->comp_npart_pot[k];
			gal_3->comp_start_part[j]			= gal_2->comp_start_part[k];
			gal_3->comp_type[j]					= gal_2->comp_type[k];
			j++;
		}
	}
	for(k=0;k<AllVars.MaxCompNumber;k++) {
		if(gal_1->comp_npart[k]>0) {
			gal_3->comp_npart[j]				= gal_1->comp_npart[k];
			gal_3->comp_npart_pot[j]			= gal_1->comp_npart_pot[k];
			gal_3->comp_start_part[j]			= gal_2->ntot_part_pot+gal_1->comp_start_part[k];
			gal_3->comp_type[j]					= gal_1->comp_type[k];
			j++;
		}
	}	
    gal_3->ntot_part 		= gal_1->ntot_part+gal_2->ntot_part;
    gal_3->ntot_part_stars 	= gal_1->ntot_part_stars+gal_2->ntot_part_stars;
    gal_3->num_part[0] 		= gal_1->num_part[0]+gal_2->num_part[0];
    gal_3->num_part[1] 		= gal_1->num_part[1]+gal_2->num_part[1];
    gal_3->num_part[2] 		= gal_1->num_part[2]+gal_2->num_part[2];
    gal_3->num_part[3] 		= gal_1->num_part[3]+gal_2->num_part[3]; 
    
    gal_3->ntot_part_pot 	= gal_1->ntot_part_pot+gal_2->ntot_part_pot;
    gal_3->num_part_pot[0] 	= gal_1->num_part_pot[0]+gal_2->num_part_pot[0];
    gal_3->num_part_pot[1] 	= gal_1->num_part_pot[1]+gal_2->num_part_pot[1];
    gal_3->num_part_pot[2] 	= gal_1->num_part_pot[2]+gal_2->num_part_pot[2];
    gal_3->num_part_pot[3] 	= gal_1->num_part_pot[3]+gal_2->num_part_pot[3]; 
    
    if(allocate_variable_arrays(gal_3)!=0) {
		fprintf(stderr,"Allocation of component arrays failed\n");
	}	

    // Turn off the galaxy potential.
    gal_3->potential_defined = 0;

    // Copy all of the galaxy information.
	a = 0;
    for (i = 0; i < gal_2->ntot_part_pot; ++i) {
        gal_3->mass[a] 		= gal_2->mass[i];
	    gal_3->id[a] 		= a;
	    gal_3->x[a] 		= gal_2->x[i];
	    gal_3->y[a] 		= gal_2->y[i];
	    gal_3->z[a] 		= gal_2->z[i];
	    gal_3->vel_x[a] 	= gal_2->vel_x[i];
   	    gal_3->vel_y[a] 	= gal_2->vel_y[i];
   	    gal_3->vel_z[a] 	= gal_2->vel_z[i];
   	    gal_3->u[a]			= gal_2->u[i];
	    gal_3->rho[a]		= gal_2->rho[i];
	    gal_3->metal[a]		= gal_2->metal[i];
	    gal_3->age[a]		= gal_2->age[i];
		a++;
   	}
    for (i = 0; i < gal_1->ntot_part_pot; ++i) {
        gal_3->mass[a] 		= gal_1->mass[i];
        gal_3->id[a] 		= a;
	    gal_3->x[a] 		= gal_1->x[i];
	    gal_3->y[a] 		= gal_1->y[i];
	    gal_3->z[a] 		= gal_1->z[i];
	    gal_3->vel_x[a] 	= gal_1->vel_x[i];
	    gal_3->vel_y[a] 	= gal_1->vel_y[i];
	    gal_3->vel_z[a] 	= gal_1->vel_z[i];
	    gal_3->u[a]			= gal_1->u[i];
	    gal_3->rho[a]		= gal_1->rho[i];
	    gal_3->metal[a]		= gal_1->metal[i];
	    gal_3->age[a]		= gal_1->age[i];
		a++;
    }
    return 0;
}

// In order to perform a galaxy collision, it is necessary to combine
// two galaxies into one set of orbiting galaxies. The orbits should
// be defined by a user-defined orbit or the set_orbit_parabolic()
// function and the following function should be called to combine
// the galaxies into one object.
//
// It is necessary to allocate the different parts of the memory here
// because this galactic system does not have quantities like halo
// or disk scale lengths. These are quantities in the parent galaxy,
// not the galaxy-orbit-galaxy combination.
int add_stream_to_system(stream *st_1, galaxy *gal_2, galaxy *gal_3) {
	unsigned long int i,a;
	int j,k;

	if(allocate_component_arrays(gal_3)!=0) {
		fprintf(stderr,"Allocation of component arrays failed\n");
		return -1;
	}
	
	// Create the galaxy system first!
	j=0;
	for(k=0;k<AllVars.MaxCompNumber;k++) {
		if(gal_2->comp_npart[k]>0) {
			gal_3->comp_npart[j]				= gal_2->comp_npart[k];
			gal_3->comp_npart_pot[j]			= gal_2->comp_npart_pot[k];
			gal_3->comp_start_part[j]			= gal_2->comp_start_part[k];
			gal_3->comp_type[j]					= gal_2->comp_type[j];
			j++;
		}
	}
	// Adding stream gas particles to the next available comp index
	if(j>=AllVars.MaxCompNumber) {
		fprintf(stderr,"No more free component. Increase MaxCompNumber\n");
		return -1;
	}
	gal_3->comp_type[j] 		= 0;
	gal_3->comp_npart[j] 		= st_1->ntot_part;
	gal_3->comp_start_part[j] 	= gal_2->ntot_part_pot;	
	
    gal_3->ntot_part 		= st_1->ntot_part+gal_2->ntot_part;
    gal_3->ntot_part_stars 	= gal_2->ntot_part_stars;
    gal_3->num_part[0] 		= gal_2->num_part[0]+st_1->ntot_part;
    gal_3->num_part[1] 		= gal_2->num_part[1];
    gal_3->num_part[2] 		= gal_2->num_part[2];
    gal_3->num_part[3] 		= gal_2->num_part[3]; 
    
    gal_3->ntot_part_pot 	= st_1->ntot_part+gal_2->ntot_part_pot;
    gal_3->num_part_pot[0] 	= st_1->ntot_part+gal_2->num_part_pot[0];
    gal_3->num_part_pot[1] 	= gal_2->num_part_pot[1];
    gal_3->num_part_pot[2] 	= gal_2->num_part_pot[2];
    gal_3->num_part_pot[3] 	= gal_2->num_part_pot[3]; 

	if(allocate_variable_arrays(gal_3)!=0) {
		fprintf(stderr,"Allocation of component arrays failed\n");
		return -1;
	}	

    // Turn off the galaxy potential.
    gal_3->potential_defined = 0;
		
    // Copy all of the galaxy information.
	a = 0;
    for (i = 0; i < gal_2->ntot_part_pot; ++i) {
        gal_3->mass[a] 		= gal_2->mass[i];
	    gal_3->id[a] 		= a;
	    gal_3->x[a] 		= gal_2->x[i];
	    gal_3->y[a] 		= gal_2->y[i];
	    gal_3->z[a] 		= gal_2->z[i];
	    gal_3->vel_x[a] 	= gal_2->vel_x[i];
   	    gal_3->vel_y[a] 	= gal_2->vel_y[i];
   	    gal_3->vel_z[a] 	= gal_2->vel_z[i];
   	    gal_3->u[a]			= gal_2->u[i];
	    gal_3->rho[a]		= gal_2->rho[i];
	    gal_3->metal[a]		= gal_2->metal[i];
	    gal_3->age[a]		= gal_2->age[i];
		a++;
   	}
	for (i = 0; i < st_1->ntot_part; ++i) {
        gal_3->mass[a] 		= st_1->mass[i];
        gal_3->id[a] 		= a;
	    gal_3->x[a] 		= st_1->x[i];
	    gal_3->y[a] 		= st_1->y[i];
	    gal_3->z[a] 		= st_1->z[i];
	    gal_3->vel_x[a] 	= st_1->vel_x[i];
	    gal_3->vel_y[a] 	= st_1->vel_y[i];
	    gal_3->vel_z[a] 	= st_1->vel_z[i];
	    gal_3->u[a]			= st_1->u[i];
	    gal_3->rho[a]		= st_1->rho[i];
	    gal_3->metal[a]		= st_1->metal[i];
		a++;
    }
    
    return 0;
}

int stream_to_galaxy(stream *st, galaxy *gal) {
	unsigned long int i,a;
	int j,k;

	if(allocate_component_arrays(gal)!=0) {
		fprintf(stderr,"Allocation of component arrays failed\n");
		return -1;
	}
	
	gal->comp_type[0] 		= 0;
	gal->comp_npart[0] 		= st->ntot_part;
	gal->comp_start_part[0] = 0;	
	
    gal->ntot_part 			= st->ntot_part;
    gal->ntot_part_stars 	= 0;
    gal->num_part[0] 		= st->ntot_part;
    gal->num_part[1] 		= 0;
    gal->num_part[2] 		= 0;
    gal->num_part[3] 		= 0; 
    
    gal->ntot_part_pot 		= st->ntot_part;
    gal->num_part_pot[0] 	= st->ntot_part;
    gal->num_part_pot[1] 	= 0;
    gal->num_part_pot[2] 	= 0;
    gal->num_part_pot[3] 	= 0; 

	if(allocate_variable_arrays(gal)!=0) {
		fprintf(stderr,"Allocation of component arrays failed\n");
		return -1;
	}	

    // Turn off the galaxy potential.
    gal->potential_defined = 0;
		
    // Copy all of the galaxy information.
	a = 0;
    for (i = 0; i < st->ntot_part; ++i) {
        gal->mass[a] 	= st->mass[i];
	    gal->id[a] 		= a;
	    gal->x[a] 		= st->x[i];
	    gal->y[a] 		= st->y[i];
	    gal->z[a] 		= st->z[i];
	    gal->vel_x[a] 	= st->vel_x[i];
   	    gal->vel_y[a] 	= st->vel_y[i];
   	    gal->vel_z[a] 	= st->vel_z[i];
   	    gal->u[a]		= st->u[i];
	    gal->rho[a]		= st->rho[i];
	    gal->metal[a]	= st->metal[i];
		a++;
   	}
    
    return 0;
}


// Copy a galaxy strucuture into a new one
int copy_galaxy(galaxy *gal_1, galaxy *gal_2, int info) {
    
	unsigned long int i;
	int j;
	
	destroy_galaxy(gal_2,0);
	// Copy all the non-pointers structures variables
	*gal_2 = *gal_1;
	
	if(allocate_component_arrays(gal_2)!=0) {
		fprintf(stderr,"Allocation of component arrays failed\n");
	}
	
	for (j = 0; j < AllVars.MaxCompNumber; ++j) {
		gal_2->comp_npart[j]				= gal_1->comp_npart[j];
		gal_2->comp_npart_pot[j]			= gal_1->comp_npart_pot[j];
		gal_2->comp_start_part[j]			= gal_1->comp_start_part[j];
		gal_2->comp_type[j]					= gal_1->comp_type[j];
	}

	if(allocate_variable_arrays(gal_2)!=0) {
		fprintf(stderr,"Allocation of component arrays failed\n");
	}	
    
	gal_2->potential_defined = 0;
		
    // Copy all the coordinate information.
    for (i = 0; i < gal_1->ntot_part_pot; ++i) {
		gal_2->x[i] 	= gal_1->x[i];
		gal_2->y[i] 	= gal_1->y[i];
		gal_2->z[i] 	= gal_1->z[i];
		gal_2->vel_x[i] = gal_1->vel_x[i];
		gal_2->vel_y[i] = gal_1->vel_y[i];
		gal_2->vel_z[i] = gal_1->vel_z[i];
		gal_2->mass[i] 	= gal_1->mass[i];
		gal_2->u[i] 	= gal_1->u[i];
	    gal_2->rho[i]	= gal_1->rho[i];
	    gal_2->metal[i]	= gal_1->metal[i];
	    gal_2->age[i]	= gal_1->age[i];
	}
	return 0;
}




// This function places two galaxies on a Keplerian orbit in the x,y
// plane. The orbit is fully parametrizable going from hyperbolic orbits to elliptic orbits,
// including the special case of parabolic orbits.
void set_orbit_keplerian(galaxy *gal_1, galaxy *gal_2, double sep, double per, double e, double phi, double theta) {
    
	unsigned long int i;
	double nu1, nu2, x_1, y_1, z_1, x_2, y_2, z_2, vx_1, vy_1, vz_1, vx_2, vy_2, vz_2, mu, angmom;
	double radius1,radius2,a1,a2,l1,l2,k1,k2,v_ini,r_ini,specific_orbital_energy,kappa,l,theta_diago, degtorad;
	double xt_1,yt_1,zt_1,vxt_1,vyt_1,vzt_1,xt_2,yt_2,zt_2,vxt_2,vyt_2,vzt_2;
   	double m1,m2;
	// Degrees to radian conversion factor
	degtorad = pi/180.;
	// Mu is the standard gravitational parameter, calculated here in
	// terms of the reduced mass.
	m1 = gal_1->total_mass;
	m2 = gal_2->total_mass;
	mu = (m1*m2)/(m1+m2);
	if(per > sep) {
		fprintf(stderr,"Warning: The pericentral distance must be lower than the initial distance.");
		fprintf(stderr,"Warning: Setting initial distance value equal to pericentral distance value.");
		sep = per;
	}
	// Mass ratios
	k1 = mu/m1;
	k2 = mu/m2;
	// Keeping the center of mass at [0,0,0]
	radius1 = k1*sep;
	radius2 = k2*sep;
	// Semi-major axis
	if( e == 1 ) a1 = k1*per; else a1 = k1*per/fabs(1.0-e);
	if( e == 1 ) a2 = k2*per; else a2 = k2*per/fabs(1.0-e);
	// Semi-latus rectum
	if( e == 1 ) l1 = 2.0*a1; else l1 = a1*fabs(1-e*e);
	if( e == 1 ) l2 = 2.0*a2; else l2 = a2*fabs(1-e*e);
	// True anomaly
	nu1 = acos((((double)l1/(radius1)) - 1.0)/e);
	nu2 = acos((((double)l2/(radius2)) - 1.0)/e);
	// Case where the galaxies are on elliptical orbits
	if(e < 1.0) {
		if(nu1!=nu1)	{
			nu1=-pi;
			radius1 = l1/(1.0-e);
		}
		if(nu2!=nu2) {
			nu2=-pi;
			radius2 = l2/(1.0-e);
		}
	}
	
	kappa = G*unit_mass*(gal_1->total_mass+gal_2->total_mass);
    
	x_1 =  (radius1)*cos(nu1);
	y_1 =  (radius1)*sin(nu1);
	z_1 = 0.;
	x_2 = -(radius2)*cos(nu2);
	y_2 = -(radius2)*sin(nu2);
	z_2 = 0.;
	
	l = per*(1.0+e);
    
	vx_1 =  k1*sqrt(kappa/(l*kpc))*sin(nu1)/1.0E5;
	vy_1 = -k1*sqrt(kappa/(l*kpc))*(e+cos(nu1))/1.0E5;
	vz_1 = 0.;
	vx_2 = -k2*sqrt(kappa/(l*kpc))*sin(nu2)/1.0E5;
	vy_2 =  k2*sqrt(kappa/(l*kpc))*(e+cos(nu2))/1.0E5;
	vz_2 = 0.;
    
	// Putting galaxies on the X-axis
	if(x_1 < 0) theta_diago = asin(y_1/radius1);
	else theta_diago = asin(-y_1/radius1);
	xt_1 = x_1*cos(theta_diago)-y_1*sin(theta_diago);
	yt_1 = x_1*sin(theta_diago)+y_1*cos(theta_diago);
	zt_1 = z_1;
	xt_2 = x_2*cos(theta_diago)-y_2*sin(theta_diago);
	yt_2 = x_2*sin(theta_diago)+y_2*cos(theta_diago);
	zt_2 = z_2;
	vxt_1 = vx_1*cos(theta_diago)-vy_1*sin(theta_diago);
	vyt_1 = vx_1*sin(theta_diago)+vy_1*cos(theta_diago);
	vzt_1 = vz_1;
	vxt_2 = vx_2*cos(theta_diago)-vy_2*sin(theta_diago);
	vyt_2 = vx_2*sin(theta_diago)+vy_2*cos(theta_diago);
	vzt_2 = vz_2;
	// Put back the new coordinates in the orginal variables
	x_1 = xt_1;
	y_1 = yt_1;
	z_1 = zt_1;
	x_2 = xt_2;
	y_2 = yt_2;
	z_2 = zt_2;
	vx_1 = vxt_1;
	vy_1 = vyt_1;
	vz_1 = vzt_1;
	vx_2 = vxt_2;
	vy_2 = vyt_2;
	vz_2 = vzt_2;
	// Computing initial distance
	r_ini = sqrt(pow(x_1-x_2,2)+pow(y_1-y_2,2)+pow(z_1-z_2,2));
	// Computing initial relative velocity
	v_ini = sqrt(pow(vx_1-vx_2,2)+pow(vy_1-vy_2,2)+pow(vz_1-vz_2,2));
	// Computing specific orbital energy in 1E4 km^2.s^-2
	specific_orbital_energy = (0.5*v_ini*v_ini-((kappa/(1E15))/(sep*kpc/1E5)))/(1.0E4);
	// Setting the trajectory informations of the two galaxies
	gal_1->xc = x_1;
	gal_1->yc = y_1;
	gal_1->zc = z_1;
	gal_1->vel_xc = vx_1;
	gal_1->vel_yc = vy_1;
	gal_1->vel_zc = vz_1;
	gal_2->xc = x_2;
	gal_2->yc = y_2;
	gal_2->zc = z_2;
	gal_2->vel_xc = vx_2;
	gal_2->vel_yc = vy_2;
	gal_2->vel_zc = vz_2;
	// Printing some informations about the trajectory to the screen
	printf("/////\n");
	printf("/////\t--------------------------------------------------\n");
	printf("/////\tSetting Keplerian orbit\n");
	printf("/////\t\t- Galaxy 1 mass                -> %8.3le Msol\n",m1*1e10);
	printf("/////\t\t- Galaxy 2 mass                -> %8.3le E10 Msol\n",m2*1e10);
	printf("/////\t\t- Initial distance             -> %6.1lf kpc\n",r_ini);
	printf("/////\t\t- Pericentral distance         -> %6.2lf kpc\n",per);
	printf("/////\t\t- Eccentricity                 -> %6.3lf\n",e);
	printf("/////\t\t- Center of galaxy 1           -> [x=%5.1lf,y=%5.1lf,z=%5.1lf] kpc\n",x_1,y_1,z_1);
	printf("/////\t\t- Center of galaxy 2           -> [x=%5.1lf,y=%5.1lf,z=%5.1lf] kpc\n",x_2,y_2,z_2);
	printf("/////\t\t- Velocity of galaxy 1         -> [vx=%6.1lf,vy=%6.1lf,vz=%6.1lf] km/s\n",vx_1,vy_1,vz_1);
	printf("/////\t\t- Velocity of galaxy 2         -> [vx=%6.1lf,vy=%6.1lf,vz=%6.1lf] km/s\n",vx_2,vy_2,vz_2);
	printf("/////\t\t- Relative velocity            -> %6.2lf km/s\n",v_ini);
	printf("/////\t\t- Specific orbital energy      -> %6.2lf 1E4 km^2/s^2\n",specific_orbital_energy);
	printf("/////\t\t- Orbital azimuthal angle      -> %6.1lf deg\n",theta);
	printf("/////\t\t- Orbital polar angle          -> %6.1lf deg\n",phi);
	printf("/////\t--------------------------------------------------\n");
	return;
}
