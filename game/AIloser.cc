#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME loser


struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }
  
  
  

  Dir nextDir(Dir& d) {
      switch(d) {
          case Bottom: return LB;
          case LB: return Left;
          case Left: return TL;
          case TL: return Top;
          case Top: return RT;
          case RT: return Right;
          case Right: return BR;
          case BR: return None;
          case None: return None;
          
          case DirSize: return DirSize;
      }
      return None;
  }
 

  
  
  
  Pos treasure_distancia_minima(Pos position) {
      vector<vector<bool>> visited(60,vector<bool>(60,false));
	
	queue<Pos> Q;
	Q.push(position);
	
	while (Q.size() > 0) {
        
		Pos p = Q.front();
		Q.pop();
		
            if (cell(p).treasure) {
                return p;
                cerr << p << endl << endl<< endl<< endl<< endl<< endl<< endl<< endl<< endl<< endl<< endl<< endl<< endl<< endl<< endl<< endl<< endl<< endl;
            }
            
            if (pos_ok(p+Bottom) and not visited[(p+Bottom).i][(p+Bottom).j]) {Q.push(p+Bottom); }
            if (pos_ok(p+BR) and not visited[(p+BR).i-1][(p+BR).j+1]) {Q.push(p+BR); }
            if (pos_ok(p+Right) and not visited[(p+Right).i][(p+Right).j+1]) {Q.push(p+Right); }
            if (pos_ok(p+RT) and not visited[(p+RT).i+1][(p+RT).j+1]) {Q.push(p+RT); }
            if (pos_ok(p+Top) and not visited[(p+Top).i+1][(p+Top).j]) {Q.push(p+Top); }
            if (pos_ok(p+TL) and not visited[(p+TL).i+1][(p+TL).j-1]) {Q.push(p+TL); }
            if (pos_ok(p+Left) and not visited[(p+Left).i][(p+Left).j-1]) {Q.push(p+Left); ;}
            if (pos_ok(p+LB) and not visited[(p+LB).i-1][(p+LB).j-1]) {Q.push(p+LB); }
            
        }
        visited[p.i][p.j] = true;
        
		
		
	}
	position.i = -1;
    position.j= -1;
	return position;
}
      

  
  /**
   * Types and attributes for your player can be defined here.
   */
    void move_dwarves() {
        vector<int> D = dwarves(me());
        int n = D.size();
        
        for (int i = 0; i < n; ++i) {
            int id = D[i];
            Pos destiny;
            
            destiny = treasure_distancia_minima(unit(id).pos);//vigilar si pot haver algo no accessible
            command(id, destiny);
        }}
            
        //dijikstra para el destiny
        //mirar si es important detecctar enemics
        //mirar si es important esquivar el balrog ----> valrog_id()
            
            
            
            
            
            
            
            //CELL ANALYSIS
           //fer una funcio de si he passat per aquell cami
            //prioritza matar als altres jugadors. 
            //avoid granite i abysmm 
            /*for (Dir k = Bottom; k != None; k = nextDir(k)) {
            Pos p = unit(id).pos + k;
                if (pos_ok(p)) {
                    int id2 = cell(p).id; //if -1 no unit 
                    if (id2 != -1 and unit(id2).player != me() and unit(id2).type != UnitType(Troll)) { // if we are next to an enemy, we attack.
                        command(id, k); //matar tenint en compte la health
                    }else if(id2 == -1 and cell(p).owner != me() and cell(p).type != CellType(Rock)){
                        command(id, k);
                    }else if(id2 == -1 and cell(p).type == CellType(Rock)){
                        int turnos = cell(p).turns;
                        for (int i = 0;i<turnos;++i){
                            //tenir en compte si quan la roca es trenca hi ha un abysmm
                            command(id, k);
                        }
                    }
                }*/
            
        
    
    
    
    void move_wizards() {
        map<int, int> kind;
        vector<int> W = wizards(me());
        for (int id : W) {
        if (kind.find(id) == kind.end()) kind[id] = random(0, 1);
        if (kind[id] == 0) command(id, Dir(2*random(0, 3)));
        else command(id, Dir(2*(round()%4)));
    }
  }
  
  
  /**
   * Play method, invoked once per each round.
   */
  virtual void play () {
      move_dwarves();
      move_wizards();
  }

};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
