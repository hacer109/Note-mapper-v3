

#include <iostream>
#include <raylib.h>
#include "Grid.h"
//#include <imgui.h>
#include "Gui.h"
#include <vector>




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
std::vector<Grid> AssignSections(std::vector<Grid> sections) {


    int numOfSections = 73;//add formula to calculate


    for (int i = 0; i < numOfSections;i++) {

        sections.push_back(Grid(100, 360+(720*i), 3));
        sections[i].offsetY = 360 + (720 * i);
        sections[i].sectionStartTime = 1.28 * i;
        sections[i].sectionEndTime = 1.28 * (i + 1);
    }
    
    return sections;
}

int main()
{
    InitWindow(1366, 768, "Note Mapper protoype");
    SetTargetFPS(60);
    InitAudioDevice();
   // Grid hi = Grid(100,360,3);
    std::vector<Grid> sections{};
    sections = AssignSections(sections);
    
    Gui gui;
    gui.maxSections = sections.size();
    Music music = LoadMusicStream("assets/sound/Philly_Nice.mp3");
   // SeekMusicStream(music, double(0.08));
    while (!WindowShouldClose())
    {


       // hi.AssignGrid();
        sections[gui.section].AssignGrid();
      //hi.GridUpdate();
        
        MusicManager(music);
        UpdateMusicStream(music);
       
        SetMusicVolume(music, gui.SongVolume);
        currentID = { (float)sections[gui.section].hoveredId,(float)sections[gui.section].hoveredId2 };
        ClearBackground(BLACK);
        BeginDrawing();
        gui.curTime = GetMusicTimePlayed(music);
        gui.songDuration = GetMusicTimeLength(music);
        
        sections[gui.section].posY = -gui.curTime * 550 + sections[gui.section].offsetY; // +360
       
       // std::cout << sections.size() << "\n" << endl;
       
        gui.x = sections[gui.section].hoveredX;
        gui.y = sections[gui.section].hoveredY;
        gui.ID = currentID.x;
        gui.ID2 = currentID.y;
        
        gui.Update();

        if (gui.curTime >= sections[gui.section].sectionEndTime) gui.section++;
        
        EndDrawing();
        
    }
   
    CloseWindow();
   

}




