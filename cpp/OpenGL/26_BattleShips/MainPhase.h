#pragma once

#include <string>
#include <optional>

#include "BoardPhase.h"
#include "GameGrid.h"

class MainPhase : public BoardPhase {
public:
  MainPhase(BattleShips* app, GamePhaseID gamePhaseID, const Vec2ui& boardSize);

  void prepare(const ShipPlacement& myShipPlacement);

  uint32_t gameOver() const;
  GameGrid getMyBoard() const {return myBoard;}
  GameGrid getOtherBoard() const {return otherBoard;}
  
private:
  Mat4 otherBoardTrans;
  Vec2ui otherCellPos{std::numeric_limits<uint32_t>::max(), std::numeric_limits<uint32_t>::max()};
  
  GameGrid myBoard{boardSize};
  GameGrid otherBoard{boardSize};
  
  std::string guestTitle;
  std::string homeTitle;
  bool waitingForOther{false};
  size_t waitingMessageIndex{0};
  
  size_t myRound{0};
  size_t otherRound{0};
  std::vector<Vec2ui> shotsFired;
  std::vector<Vec2ui> shotsResponded;
  std::vector<Vec2ui> shotsReceived;
  std::vector<ShotResult> shotResults;

  void drawBoard(const GameGrid& board, Mat4 boardTrans, Vec2ui aimCoords);
  
  virtual void mouseMoveInternal(double xPosition, double yPosition) override;
  virtual void mouseButtonInternal(int button, int state, int mods,
                           double xPosition, double yPosition) override;
  virtual void animateInternal(double animationTime) override;
  virtual void drawInternal() override;
};
