// โปรดอ่าน ระบบนี้ทำโดย NSTIOM แจกต่อหรือสอนต่อ ให้เครดิตด้วยน่ะครับ

// Copyright By NSTIOM 2024







#include <YSI_Coding\y_hooks>
#define AUTO_WALK_INTERVAL 500
forward AutoWalkCheck(playerid, Float:targetX, Float:targetY);
new bool:n_Autofarm_Jobs[MAX_PLAYERS];
new bool:n_walkplayerid[MAX_PLAYERS];
new bool:n_player_ProgressFinish[MAX_PLAYERS];

stock SetFacingPoint(playerid, Float:x, Float:y)
{
    new Float:pX, Float:pY, Float:pZ;
    GetPlayerPos(playerid, pX, pY, pZ);

    new Float:angle;

    if( y > pY ) angle = (-acos((x - pX) / floatsqroot((x - pX)*(x - pX) + (y - pY)*(y - pY))) - 90.0);
    else if( y < pY && x < pX ) angle = (acos((x - pX) / floatsqroot((x - pX)*(x - pX) + (y - pY)*(y - pY))) - 450.0);
    else if( y < pY ) angle = (acos((x - pX) / floatsqroot((x - pX)*(x - pX) + (y - pY)*(y - pY))) - 90.0);

    if(x > pX) angle = (floatabs(floatabs(angle) + 180.0));
    else angle = (floatabs(angle) - 180.0);

    return SetPlayerFacingAngle(playerid, angle);
}

stock GetXYFromAngle(&Float:x, &Float:y, Float:a, Float:distance) 
{
    x += (distance*floatsin(-a,degrees));
    y += (distance*floatcos(-a,degrees));
}

Float:GetAbsoluteAngle(Float:angle) 
{
	while(angle < 0.0) {
		angle += 360.0;
	}
	while(angle > 360.0) {
		angle -= 360.0;
	}
	return angle;
}

Float:GetAngleToPoint(Float:fPointX, Float:fPointY, Float:fDestX, Float:fDestY) 
{
	return GetAbsoluteAngle(-(
		90.0 - (
			atan2(
				(fDestY - fPointY),
				(fDestX - fPointX)
			)
		)
	));
}




n_clear_auto_farm(playerid) {
    SendClientMessage(playerid, COLOR_GREEN, "[Auto Farm]: ระบบฟาร์มอัตโนมัติปิดอยู่ เนื่องจากกระเป๋าเต็ม");
    n_player_ProgressFinish[playerid] = false;
    n_walkplayerid[playerid] = false;
    n_Autofarm_Jobs[playerid] = false;
    ClearAnimations(playerid);
    return 1;
}



CMD:autofarm(playerid) {
    if(!n_Autofarm_Jobs[playerid]) {
        n_Autofarm_Jobs[playerid] = true;
        SendClientMessage(playerid, COLOR_GREEN, "[Auto Farm]: คุณได้ทำการเปิดการ ฟาร์มอัตโนมัติ แล้ว");
    } else {
        n_Autofarm_Jobs[playerid] = false;
        SendClientMessage(playerid, COLOR_GREEN, "[Auto Farm]: คุณได้ทำการปิดการ ฟาร์มอัตโนมัติ แล้ว");
		ClearAnimations(playerid);
    }
	return 1;
}


n_autowalk(playerid, Float:targetX, Float:targetY) {
    new Float:pX, Float:pY, Float:pZ;
    if (n_walkplayerid[playerid]) {
        GetPlayerPos(playerid, pX, pY, pZ);
        
        new Float:angle = GetAngleToPoint(pX, pY, targetX, targetY);
        SetPlayerFacingAngle(playerid, angle);
        ApplyAnimation(playerid, "ped", "run_civi", 4.1, 1, 1, 1, 1, 0);
    }
    return 1;
}



ptask n_taskloopStatAuto[1000](playerid) {
	if(n_Autofarm_Jobs[playerid]) {
		// ใส่ฟั่งชั่น ที่ทำเสร็จที่นี้
	}
	return 1;
}



hook OnPlayerDisconnect(playerid, reason) {
    return n_Autofarm_Jobs[playerid] = false;
}







//                  ///////////// ตัวอย่างการใช้งาน /////////////
hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys){
	if(newkeys & KEY_NO && !IsPlayerInAnyVehicle(playerid)){
        if(WOOD_JOB_STATS[playerid] == 0){
            for(new i = 0; i < sizeof WOODDATA; i++){
                GetDynamicObjectPos(WOODDATA[i][WOODID], WOODDATA[i][WOODPOS_X], WOODDATA[i][WOODPOS_Y], WOODDATA[i][WOODPOS_Z]);
                if(IsPlayerInRangeOfPoint(playerid, 3.0, WOODDATA[i][WOODPOS_X], WOODDATA[i][WOODPOS_Y], WOODDATA[i][WOODPOS_Z])){
                    if(IsValidDynamicObject(WOODDATA[i][WOODID]) && WOODDATA[i][WOODON] == 0){
                        if(Inventory_amount(playerid, WOOD_ITEM) >= WOOD_AMOUNT) return ServerMsg(playerid, "ไอเท็มในกระเป๋าของคุณเต็มแล้ว");
                        WOODDATA[i][WOODON] = 1;
                        StartingBar(playerid, 50, i);
                        WOOD_JOB_STATS[playerid] = 1;
                        ApplyAnimation(playerid, "BOMBER", "BOM_PLANT_LOOP", 4.0, 1, 0, 0, 0, 0, 1);
                        break;
                    }
                }
            }
        }
	}
	return 1;
}


n_AutoFarmGetStartwood(playerid) {
    new Float:pX, Float:pY, Float:pZ;
    GetPlayerPos(playerid, pX, pY, pZ);
    if (n_Autofarm_Jobs[playerid]) {
        for(new i = 0; i < sizeof WOODDATA; i++) { ///
            if (IsValidDynamicObject(WOODDATA[i][WOODID]) && WOODDATA[i][WOODON] == 0) { ///
                if(IsPlayerInRangeOfPoint(playerid, 25.0, WOODDATA[i][WOODPOS_X], WOODDATA[i][WOODPOS_Y], WOODDATA[i][WOODPOS_Z])) { //
                    GetDynamicObjectPos(WOODDATA[i][WOODID], WOODDATA[i][WOODPOS_X], WOODDATA[i][WOODPOS_Y], WOODDATA[i][WOODPOS_Z]);//
                    if (n_Autofarm_Jobs[playerid]) {
                        if (n_player_ProgressFinish[playerid]) {
                            n_walkplayerid[playerid] = true;
                            n_autowalk(playerid, WOODDATA[i][WOODPOS_X], WOODDATA[i][WOODPOS_Y]); ///
                            if(IsPlayerInRangeOfPoint(playerid, 3.0, WOODDATA[i][WOODPOS_X], WOODDATA[i][WOODPOS_Y], WOODDATA[i][WOODPOS_Z])) {//
                                if(Inventory_amount(playerid, WOOD_ITEM) >= WOOD_AMOUNT) return n_clear_auto_farm(playerid);
                                n_player_ProgressFinish[playerid] = false;
                                n_walkplayerid[playerid] = false;
                                ClearAnimations(playerid);
                                WOODDATA[i][WOODON] = 1;
                                StartingBar(playerid, 50, i);
                                WOOD_JOB_STATS[playerid] = 1;
                                ApplyAnimation(playerid, "BOMBER", "BOM_PLANT_LOOP", 4.0, 1, 0, 0, 0, 0, 1);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    return 1;
}


hook OnProgressFinish(playerid, objectid){
	if(WOOD_JOB_STATS[playerid] == 1)
		PLAYER_WOOD_UNFREEZE(playerid, objectid);
	return Y_HOOKS_CONTINUE_RETURN_0;
}
PLAYER_WOOD_UNFREEZE(playerid, number){
	ClearAnimations(playerid);
	WOODDATA[number][WOODON] = 0;
	WOOD_JOB_STATS[playerid] = 0;
    new x = randomEx(1, 2);
	new id = Inventory_Add(playerid, WOOD_ITEM, x);
	if(id == -1) return ErrorMsg(playerid, "กระเป๋าคุณเต็มแล้ว!");
    if(IsValidDynamicObject(WOODDATA[number][WOODID])){
        DestroyDynamicObject(WOODDATA[number][WOODID]);
        WOODDATA[number][WOODID] = INVALID_OBJECT_ID;
    }
	SetTimerEx("RESET_WOOD_OBJECT", 10000, false, "d", number);
	ServerMsgEx(playerid, "คุณได้รับ "#WOOD_ITEM" +%d", x);
    GivePlayerExp(playerid, 15);
    n_player_ProgressFinish[playerid] = true;
	return 1;
}
/////////////////////////////////////////////////////////////////////////////////
