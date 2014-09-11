enum soundsFxChannel_t {
  SND_FX_CHANNEL_1 = 0,
  SND_FX_CHANNEL_2 = 1,
  SND_FX_CHANNEL_3 = 2,
  SND_FX_CHANNEL_4 = 3
};

enum soundsFx_t {
  SND_FX_LINE_COMPLETED = 0,
  SND_FX_ROTATE         = 1,
  SND_FX_GAME_OVER      = 2,
  SND_FX_PIECE_DROP     = 3
};

const int soundfx[4][8] = {
  {0,34,75,1,0,1,7,11}, // SND_FX_LINE_COMPLETED
  {0,33,53,1,0,5,7,3},  // SND_FX_ROTATE
  {0,30,34,10,0,1,7,25}, // SND_FX_GAME_OVER
  {1,1,0,0,0,0,7,2} // SND_FX_PIECE_DROP
};

void PlaySoundFxGameOver() {
  PlaySoundFx(SND_FX_GAME_OVER, SND_FX_CHANNEL_1);
}

void PlaySoundFxLineCompleted() {
  PlaySoundFx(SND_FX_LINE_COMPLETED, SND_FX_CHANNEL_1);
}

void PlaySoundFxRotation() {
  PlaySoundFx(SND_FX_ROTATE, SND_FX_CHANNEL_1);
}

void PlaySoundFxPieceDrop() {
  PlaySoundFx(SND_FX_PIECE_DROP, SND_FX_CHANNEL_1);
}

//Play Gambuino sound effect (http://www.yodasvideoarcade.com/gamebuino.php)
void PlaySoundFx(int fxno, int channel) {
  gb.sound.command(0,soundfx[fxno][6],0,channel); // set volume
  gb.sound.command(1,soundfx[fxno][0],0,channel); // set waveform
  gb.sound.command(2,soundfx[fxno][5],-soundfx[fxno][4],channel); // set volume slide
  gb.sound.command(3,soundfx[fxno][3],soundfx[fxno][2]-58,channel); // set pitch slide
  gb.sound.playNote(soundfx[fxno][1],soundfx[fxno][7],channel); // play note
}

