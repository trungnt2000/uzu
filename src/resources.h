#ifndef RESOURCES_H
#define RESOURCES_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <toolbox/toolbox.h>
typedef enum
{
  TEX_BIG_DEMON,
  TEX_KNIGHT,
  TEX_AXE,
  TEX_ANIME_SWORD,
  TEX_BLOOD,
  TEX_BOW,
  TEX_ARROW,
  TEX_RED_THUNDER,
  TEX_YELLOW_THUNDER,
  TEX_GOLDEN_SWORD,
  TEX_GOLDEN_CROSS_HIT,
  TEX_TILESET,
  TEX_FLASK_RED_BIG,
  TEX_FLASK_RED,
  TEX_PLAYER_HEALTH_BAR,
  TEX_CHORT,
  TEX_CLEAVER,
  NUM_TEXS
} TextureId;

typedef enum
{
  BG_MUS_AROUND_THE_BEND,
  BG_MUS_BEHIND_THE_COLUMN,
  BG_MUS_CATCH_THE_MYSTERY,
  BG_MUS_DARK_INTENSIONS,
  BG_MUS_FANCY_CAKES,
  BG_MUS_IN_DENFESE_OF_MY_STUFF,
  BG_MUS_IN_EARLY_TIME,
  BG_MUS_INSIDE_DREAM,
  BG_MUS_IN_BACK_POCKET,
  BG_MUS_IN_THE_CHAMP_ELYSEES,
  BG_MUS_IN_THE_DEPTHS_OF_CAVE,
  BG_MUS_IN_THE_SPINNING,
  BG_MUS_KILLING_FLIES,
  BG_MUS_THE_CARANE_DANCE,
  BG_MUS_THE_ESSENSE_OF_GOOD_THINGS,
  BG_MUS_UNDER_HOT_SUN,
  BG_MUS_WAITING_FOR_EVENT,
  BG_MUS_WITH_DIRTY_HAND,
  BG_MUS_WITH_LOOSE_CORDS,
  BG_MUS_WITH_TORN_PANTS,
  NUM_BG_MUSICS,
} BgMusId;

typedef enum
{
  FONT_DAMAGE_INDICATOR,
  FONT_ITEM_PICKED_UP,
  NUM_FONTS,
} FontId;

typedef enum
{
  SFX_SWORD_HIT,
  SFX_THUNDER,
  SFX_INTERACTION,
  SFX_CLAW_HIT,
  NUM_SFXS,
} SfxId;

BOOL         resources_load    (void        );
void         resources_unload  (void        );
SDL_Texture* get_texture       (TextureId id);
Mix_Music*   get_bg_mus        (BgMusId   id);
Mix_Chunk*   get_sfx           (SfxId     id);
FONT*        get_font          (FontId    id);

#endif // RESOURCES_H
