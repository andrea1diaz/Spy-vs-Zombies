//
// Created by massi on 10/10/2018.
//

#ifndef PROYECTO_SCOREMANAGER_H
#define PROYECTO_SCOREMANAGER_H


class ScoreManager {
    int CurrentScore;
    int HighScore;
    int ScoreIncrementFactor;
public:
    ScoreManager(int cscore, int hscore, int sfactor);
    void DoIncrementScore();
    void DoSaveScore();

};


#endif //PROYECTO_SCOREMANAGER_H
