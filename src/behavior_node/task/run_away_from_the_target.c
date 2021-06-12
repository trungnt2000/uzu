#include "bttask.h"
#include "components.h"

struct BTTask_RunAwayFromTheTarget
{
  BT_EXTEND_NODE(BTNode)
  float distance;
  BOOL  is_running;
};

static const BTNodeVtbl* __vtbl_inst();
static void              __vtbl_init(BTNodeVtbl* vtbl);

#define NODE BTTask_RunAwayFromTheTarget

static NODE*    __init(NODE*, float);
static void     __abort(NODE*, Ecs*, ecs_entity_t);
static void     __finish(NODE*, Ecs*, ecs_entity_t, BTStatus);
static BTStatus __exec(NODE*, Ecs*, ecs_entity_t);

BT_STATIC_VTBL_INST_FN(BTNode, _)
BT_ALLOC_FN(NODE, _)

static void __vtbl_init(BTNodeVtbl* vtbl)
{
  bt_node_init(vtbl);
  vtbl->parent = bt_node_vtbl_inst();
  vtbl->abort  = (bt_abort_fn_t)__abort;
  vtbl->exec   = (bt_exec_fn_t)__exec;
  vtbl->finish = (bt_finish_fn_t)__finish;
}

NODE* bt_task_run_away_from_the_target_new(float distance)
{
  return __init(__alloc(), distance);
}

static NODE* __init(NODE* self, float distance)
{
  bt_node_init((BTNode*)self);
  self->distance   = distance;
  self->is_running = FALSE;
  return self;
}

static void __finish(NODE*      self,
                     SDL_UNUSED Ecs*         ecs,
                     SDL_UNUSED ecs_entity_t entity,
                     SDL_UNUSED BTStatus     finish_status)
{
  sel->is_running = FALSE;
}

static void __about(NODE* self, Ecs* ecs, ecs_entity_t entity)
{
  self->is_running = FALSE;
  ecs_rmv(ecs, entity, RUNNING_AWAY_TARGET);
}

static BTStatus __exec(NODE* self, ECS* ecs, ecs_entity_t entity)
{
  AttackTarget* attack_target;
  if (self->is_running)
  {
    return (ecs_has(ecs, entity, RUNNING_AWAY_TARGET) ? BT_STATUS_RUNNING : BT_STATUS_SUCCESS;
  }
  else if((attack_target = ecs_get(ecs, entity,RUNNING_AWAY_TARGET
        {
    self->is_running = TRUE;
    ecs_set(ecs,
            entity,
            RUNNING_AWAY_TARGET,
            &(RunningAwayTarget){ attack_target->value, .radius = self->distance });
    return BT_STATUS_RUNNING;
        }
        return BT_STATUS_FAILURE;
}

#undef NODE
