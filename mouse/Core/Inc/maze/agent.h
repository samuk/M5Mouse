#ifndef M5_MAZE_AGENT_H_
#define M5_MAZE_AGENT_H_

#include "maze.h"
#include "mouse.h"
#define M5_MAZE_WIDTH (180.0f)

typedef enum {
  M5_DIR_NORTH = 0x00U,
  M5_DIR_EAST = 0x01U,
  M5_DIR_SOUTH = 0x02U,
  M5_DIR_WEST = 0x03U
} m5Direction;

typedef enum {
  M5_CURVE_SPIN = 0x00U,
  M5_CURVE_SLALOM = 0x01U
} m5CurveMode;

typedef enum {
  M5_DIR_FORWARD = 0x00U,
  M5_DIR_RIGHT = 0x01U,
  M5_DIR_BACKWARD = 0x02U,
  M5_DIR_LEFT = 0x03U,
} m5RelativeDirection;

typedef enum {
  M5_AGENT_STATE_GOAL = 0x00U,
  M5_AGENT_STATE_SEARCHING = 0x01U,
  M5_AGENT_STATE_RUNNING = 0x02U,
  M5_AGENT_STATE_GOING_HOME = 0x03U
} m5AgentState;

typedef struct {
  m5Maze maze;
  m5Maze _maze;
  m5Mouse mouse;
  m5AgentState state;
  m5Index position;
  m5Direction direction;
  m5Index goal;
  m5CurveMode curve_mode;
  uint8_t straight_count;
  m5Velocity curving_velocity;
  m5Velocity max_velocity;
} m5MazeAgentRecord, *m5MazeAgent;

m5MazeAgent m5mazeagent_constructor(m5Maze maze, m5Mouse mouse);
void m5agent_advance(m5MazeAgent agent);
void m5agent_go_forward(m5MazeAgent agent, uint8_t force);
void m5agent_turn_left(m5MazeAgent agent);
void m5agent_turn_right(m5MazeAgent agent);
void m5agent_go_backward(m5MazeAgent agent, uint8_t adjust);
m5Cell m5agent_get_wall(m5MazeAgent agent);
m5Direction m5agent_get_next_direction(m5MazeAgent agent);
void m5agent_search_run(m5MazeAgent agent, m5Index goal);
void m5agent_fast_run(m5MazeAgent agent, m5Index goal);

#endif
