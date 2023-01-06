/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_path.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:25:28 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/05 13:57:11 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_PATH_H
# define ASSETS_PATH_H

# define ASSET_SIZE 32

/* ---- Normal floors ---- */

# define BASIC_FLOOR		"./assets/floor/base.xpm"
# define FLOOR_BL_CORNER	"./assets/floor/bottom_left_corner.xpm"
# define FLOOR_BR_CORNER 	"./assets/floor/bottom_right_corner.xpm"
# define FLOOR_TL_CORNER 	"./assets/floor/top_left_corner.xpm"
# define FLOOR_TR_CORNER 	"./assets/floor/top_right_corner.xpm"
# define STAIRS			 	"./assets/floor/stairs.xpm"

/* ---- Cracked floors ---- */

# define FLOOR_CRACK_B		"./assets/floor/cracked/bottom.xpm"
# define FLOOR_CRACK_BL		"./assets/floor/cracked/bottom_left.xpm"
# define FLOOR_CRACK_BR		"./assets/floor/cracked/bottom_right.xpm"
# define FLOOR_CRACK_T		"./assets/floor/cracked/top.xpm"
# define FLOOR_CRACK_TL		"./assets/floor/cracked/top_left.xpm"
# define FLOOR_CRACK_TR		"./assets/floor/cracked/top_right.xpm"
# define FLOOR_CRACK_L		"./assets/floor/cracked/left.xpm"
# define FLOOR_CRACK_R		"./assets/floor/cracked/right.xpm"
# define FLOOR_CRACK_FULL	"./assets/floor/cracked/full.xpm"

/* ---- Holes ---- */

# define HOLE_B				"./assets/floor/hole/bottom.xpm"
# define HOLE_BL			"./assets/floor/hole/bottom_left.xpm"
# define HOLE_BR			"./assets/floor/hole/bottom_right.xpm"
# define HOLE_T				"./assets/floor/hole/top.xpm"
# define HOLE_TL			"./assets/floor/hole/top_left.xpm"
# define HOLE_TR			"./assets/floor/hole/top_right.xpm"
# define HOLE_L				"./assets/floor/hole/left.xpm"
# define HOLE_R				"./assets/floor/hole/right.xpm"
# define HOLE_CENTER		"./assets/floor/hole/center.xpm"
# define LITTLE_HOLE		"./assets/floor/hole/little.xpm"

/* ==== Wall assets paths ==== */

# define WALL_FULL			"./assets/wall/full.xpm"
# define WALL_L				"./assets/wall/left.xpm"
# define WALL_L2			"./assets/wall/left2.xpm"
# define WALL_LR			"./assets/wall/left_right.xpm"
# define WALL_R				"./assets/wall/right.xpm"
# define WALL_R2			"./assets/wall/right2.xpm"
# define WALL_T				"./assets/wall/top.xpm"
# define WALL_T2			"./assets/wall/top2.xpm"
# define WALL_TB			"./assets/wall/top_bottom.xpm"
# define WALL_TL			"./assets/wall/top_left.xpm"
# define WALL_TR			"./assets/wall/top_right.xpm"

/* ==== Decor assets paths ==== */

# define DECOR_BIG_ROCK		"./assets/decor/big_rock.xpm"
# define DECOR_BONES		"./assets/decor/bones.xpm"
# define DECOR_CRYSTAL		"./assets/decor/crystal.xpm"
# define DECOR_DIRT			"./assets/decor/dirt.xpm"
# define DECOR_LITTLE_ROCK	"./assets/decor/little_rock.xpm"
# define DECOR_MOSS			"./assets/decor/moss.xpm"
# define DECOR_MUSHROOM		"./assets/decor/mushroom.xpm"

/* ==== Collectible ==== */

# define COLLECTIBLE DECOR_CRYSTAL

/* ==== Player ==== */
# define PLAYER_FRONT		"./assets/character/front.xpm"
# define PLAYER_FRONT_LEFT	"./assets/character/front_left.xpm"
# define PLAYER_FRONT_RIGHT	"./assets/character/front_right.xpm"

# define PLAYER_LEFT		"./assets/character/left.xpm"
# define PLAYER_LEFT_LEFT	"./assets/character/left_left.xpm"
# define PLAYER_LEFT_RIGHT	"./assets/character/left_right.xpm"

# define PLAYER_RIGHT		"./assets/character/right.xpm"
# define PLAYER_RIGHT_LEFT	"./assets/character/right_left.xpm"
# define PLAYER_RIGHT_RIGHT	"./assets/character/right_right.xpm"

# define PLAYER_BACK		"./assets/character/back.xpm"
# define PLAYER_BACK_LEFT	"./assets/character/back_left.xpm"
# define PLAYER_BACK_RIGHT	"./assets/character/back_right.xpm"

#endif
