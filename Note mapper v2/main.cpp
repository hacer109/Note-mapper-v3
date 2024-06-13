

#include <iostream>
#include <raylib.h>
#include "Grid.h"
#include <imgui.h>
#include "Gui.h"




Vector2 currentID;

struct MusicNote {

    float TimeToHit;
    int SpawnLane[8];
    int Length;
    int NoteOffset;

};

float curTime;
bool musicPlaying = false;


void GenerateSections() {


}
void MusicManager(Music music) {

    
    if (IsKeyPressed(KEY_SPACE)) {
        musicPlaying = !musicPlaying;
    }

    if (musicPlaying)PlayMusicStream(music);
    else  PauseMusicStream(music);

    if (IsKeyPressed(KEY_U)&& !musicPlaying) {
        
        curTime = GetMusicTimePlayed(music);
        
        curTime += double(0.08);
        cout << curTime << " U TimePlayed  " << GetMusicTimePlayed(music) <<"\n";
        SeekMusicStream(music, curTime);
        
    }
    else if (IsKeyPressed(KEY_Y) && !musicPlaying) {
        
        curTime = GetMusicTimePlayed(music);
        curTime -= double(0.08);
        cout << curTime << " Y TimePlayed  " << GetMusicTimePlayed(music) << "\n";
        SeekMusicStream(music, curTime);
    }
   

    
    
}



int main()
{
    InitWindow(1366, 768, "Note Mapper protoype");
    SetTargetFPS(60);
    InitAudioDevice();
    Grid hi = Grid(100,360,3);
   
    Gui gui;
    Music music = LoadMusicStream("assets/sound/Philly_Nice.mp3");
    SeekMusicStream(music, double(0.08));
    while (!WindowShouldClose())
    {
        hi.AssignGrid();
      //hi.GridUpdate();
        
        MusicManager(music);
        UpdateMusicStream(music);
       
        SetMusicVolume(music, gui.SongVolume);
        currentID = { (float)hi.hoveredId,(float)hi.hoveredId2 };
        ClearBackground(BLACK);
        BeginDrawing();
        gui.curTime = GetMusicTimePlayed(music);
        gui.songDuration = GetMusicTimeLength(music);
        
        hi.posY = -gui.curTime * 550 + 360;
       
        
       
        gui.x = hi.hoveredX;
        gui.y = hi.hoveredY;
        gui.ID = currentID.x;
        gui.ID2 = currentID.y;
        
        gui.Update();
        EndDrawing();
        
    }
   
    CloseWindow();
   

}




