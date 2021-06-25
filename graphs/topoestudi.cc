#include <iostream>
#include <vector>
#include <queue>
#include <list>
 

 
using namespace std;
 
 
void ordenacio_topologica(vector< vector<int> > &tasques, vector<int> &visited) {
    int n = tasques.size();
    priority_queue<int, vector<int>, greater<int>> cola_prioridad; //sortiran els valors (top) de petit a gran
 
    for (int i = 0; i < n; i++)
        if (visited[i] == 0) cola_prioridad.push(i);
        
        /* 1. Creacio priority queue
         * 2. Ficar els primers valors a la pqueue (invertint ordre, forma rara)
         * 3. el while fins que la pqueu esta buida amb tot lo del top i pop. 
         * 4. mirar les adjacencies de la posició que has trobat amb el top de la pqueue.
         * 5. al fer 4. veure quan he de ficar mes coses a la pqueue o s'acaba el bucle
         * 6. a vegade s a la mateixa funció es mes facil fer la escriptura.
         
         
         
         */
 
    list<int> lista;
    while (not cola_prioridad.empty()) {
        int u = cola_prioridad.top();
        lista.push_back(u);
        cola_prioridad.pop();
        //el swap de llistes amb el pop i tot aixo.
        int m = tasques[u].size();
        //per cada valor que no estava visitat, mirarem totes les seves adjacencies
        for (int i = 0; i < m; i++) {
            int v = tasques[u][i]; //per aixo tasques era una matriu. 
            if (--visited[v] == 0) cola_prioridad.push(v); //si aquest numero ha estat visitat UNA vegada, el fico a la priority queue, sino el numero no m'importa. si es visitat mes duna vegada, haure reduit el numero sense ficarlo a la pqueue, ja el trobare. i sino estava visitat pues aqui li importa que hi sigui a la pqueue. 
            
        }
    }
    
    //ESCRIPTURA DELS RESULTATS. la llista no fa res mes que guarda el resultat perque el puguem imprimir despres. 
 
    if (not lista.empty()) {
		cout << lista.front(); 
		lista.pop_front();
	}
    while (not lista.empty()) {
        cout << ' ' << lista.front();
        lista.pop_front();
    }
}
 
int main() {
    int n, m;
    while (cin >> n >> m) {
        vector< vector<int> > ordre(n);
        vector<int> visited(n, 0);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            ordre[u].push_back(v);
            visited[v] = visited[v]+1;
        }
        ordenacio_topologica(ordre, visited); //ordre son les accions o tasques que aura de fer el problema per fer lo de les precendencies.
        cout << endl;
    }
}
