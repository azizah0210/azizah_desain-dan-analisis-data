#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <limits>
#include <algorithm>
#include <iomanip>

const int INF = std::numeric_limits<int>::max();

struct NodeDijkstra {
    std::string name;
    int distance;

    bool operator>(const NodeDijkstra& other) const {
        return distance > other.distance;
    }
};

void printPath(const std::map<std::string, std::string>& predecessors,
               const std::string& start_node,
               const std::string& end_node) {
    if (predecessors.find(end_node) == predecessors.end() || (predecessors.at(end_node).empty() && start_node != end_node)) {
        std::cout << "Tidak ada jalur.";
        return;
    }

    std::vector<std::string> path;
    std::string current = end_node;

    while (!current.empty() && current != start_node) {
        path.insert(path.begin(), current);
        current = predecessors.at(current);
    }
    path.insert(path.begin(), start_node);

    for (size_t i = 0; i < path.size(); ++i) {
        std::cout << path[i];
        if (i < path.size() - 1) {
            std::cout << " -> ";
        }
    }
}

void runDijkstra(const std::map<std::string, std::map<std::string, int>>& graph,
                 const std::string& start_node,
                 const std::string& end_node) {
    std::map<std::string, int> distances;
    std::map<std::string, std::string> predecessors;
    std::priority_queue<NodeDijkstra, std::vector<NodeDijkstra>, std::greater<NodeDijkstra>> pq;

    for (const auto& pair : graph) {
        distances[pair.first] = INF;
        predecessors[pair.first] = "";
    }
    distances[start_node] = 0;
    pq.push({start_node, 0});

    while (!pq.empty()) {
        NodeDijkstra current = pq.top();
        pq.pop();

        std::string current_name = current.name;
        int current_dist = current.distance;

        if (current_dist > distances[current_name]) {
            continue;
        }

        if (current_name == end_node) {
            break;
        }

        for (const auto& neighbor_pair : graph.at(current_name)) {
            std::string neighbor_name = neighbor_pair.first;
            int weight = neighbor_pair.second;

            if (distances[current_name] != INF && distances[current_name] + weight < distances[neighbor_name]) {
                distances[neighbor_name] = distances[current_name] + weight;
                predecessors[neighbor_name] = current_name;
                pq.push({neighbor_name, distances[neighbor_name]});
            }
        }
    }

    std::cout << "\n--- 1. Jalur Tercepat Pengiriman Pesan (Dijkstra) ---" << std::endl;
    std::cout << "Dari: " << start_node << " Ke: " << end_node << std::endl;

    if (distances[end_node] == INF) {
        std::cout << "Tidak ada jalur yang tersedia." << std::endl;
    } else {
        std::cout << "Waktu tercepat: " << distances[end_node] << std::endl;
        std::cout << "Jalur: ";
        printPath(predecessors, start_node, end_node);
        std::cout << std::endl;
    }
}

void runFloydWarshall(const std::map<std::string, std::map<std::string, int>>& graph,
                      const std::string& start_node_fw,
                      bool print_matrix) {
    std::vector<std::string> nodes;
    for (const auto& pair : graph) {
        nodes.push_back(pair.first);
    }
    std::sort(nodes.begin(), nodes.end());

    int N = nodes.size();
    std::vector<std::vector<int>> dist(N, std::vector<int>(N, INF));
    std::vector<std::vector<int>> next_node(N, std::vector<int>(N, -1));

    for (int i = 0; i < N; ++i) {
        dist[i][i] = 0;
        for (const auto& neighbor_pair : graph.at(nodes[i])) {
            auto it = std::find(nodes.begin(), nodes.end(), neighbor_pair.first);
            int j = std::distance(nodes.begin(), it);
            dist[i][j] = neighbor_pair.second;
            next_node[i][j] = j;
        }
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        next_node[i][j] = next_node[i][k];
                    }
                }
            }
        }
    }

    if (print_matrix) {
        std::cout << "\n--- Matriks Jarak Terpendek (Floyd-Warshall) ---" << std::endl;
        std::cout << "      ";
        for (const auto& node_name : nodes) {
            std::cout << std::setw(8) << node_name;
        }
        std::cout << std::endl;
        std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

        for (int i = 0; i < N; ++i) {
            std::cout << std::setw(8) << nodes[i];
            for (int j = 0; j < N; ++j) {
                if (dist[i][j] == INF) {
                    std::cout << std::setw(8) << "INF";
                } else {
                    std::cout << std::setw(8) << dist[i][j];
                }
            }
            std::cout << std::endl;
        }
    }

    std::cout << "\n--- 2. Semua Kemungkinan Pengiriman Pesan dari " << start_node_fw << " (Floyd-Warshall) ---" << std::endl;

    auto it_start_fw = std::find(nodes.begin(), nodes.end(), start_node_fw);
    if (it_start_fw == nodes.end()) {
        std::cout << "Node awal tidak ditemukan: " << start_node_fw << std::endl;
        return;
    }
    int start_fw_idx = std::distance(nodes.begin(), it_start_fw);

    for (int i = 0; i < N; ++i) {
        std::string destination_node = nodes[i];
        if (destination_node == start_node_fw) {
            continue;
        }

        int time_fw = dist[start_fw_idx][i];

        std::cout << "\nDari " << start_node_fw << " ke " << destination_node << ":" << std::endl;
        if (time_fw == INF) {
            std::cout << "  Tidak ada jalur yang tersedia." << std::endl;
        } else {
            std::cout << "  Waktu tercepat: " << time_fw << std::endl;
            std::cout << "  Jalur: ";

            std::string current_path_node = start_node_fw;
            std::cout << current_path_node;

            int current_idx = start_fw_idx;
            int dest_idx = i;

            while (current_idx != dest_idx && next_node[current_idx][dest_idx] != -1) {
                current_idx = next_node[current_idx][dest_idx];
                std::cout << " -> " << nodes[current_idx];
            }
            std::cout << std::endl;
        }
    }
}

int main() {
    std::map<std::string, std::map<std::string, int>> graph = {
        {"Kyanka", {{"Dava", 1}, {"Abrar", 3}}},
        {"Dava", {{"Kyanka", 1}, {"Doni", 1}, {"Azizah", 2}}},
        {"Doni", {{"Dava", 1}, {"Wildan", 2}, {"Annisa", 4}}},
        {"Wildan", {{"Doni", 2}, {"Jonathan", 1}, {"Haikal", 4}}},
        {"Haikal", {{"Wildan", 4}, {"Agus", 4}, {"Rofii", 2}}},
        {"Agus", {{"Haikal", 4}, {"Rofii", 2}}},
        {"Abrar", {{"Kyanka", 3}, {"Azizah", 1}, {"Steven", 2}}},
        {"Azizah", {{"Dava", 2}, {"Abrar", 1}, {"Annisa", 1}, {"Steven", 1}}},
        {"Annisa", {{"Azizah", 1}, {"Doni", 4}, {"Jonathan", 1}, {"Yunita", 2}}},
        {"Jonathan", {{"Wildan", 1}, {"Annisa", 1}, {"Rofii", 2}, {"Nanda", 2}}},
        {"Rofii", {{"Haikal", 2}, {"Jonathan", 2}, {"Agus", 2}, {"Ale", 2}}},
        {"Steven", {{"Abrar", 2}, {"Azizah", 1}}},
        {"Yunita", {{"Annisa", 2}, {"Nanda", 1}}},
        {"Nanda", {{"Jonathan", 2}, {"Yunita", 1}, {"Martin", 1}, {"Sudrajat", 4}, {"Ale", 2}}},
        {"Martin", {{"Nanda", 1}, {"Sudrajat", 3}}},
        {"Sudrajat", {{"Nanda", 4}, {"Martin", 3}}},
        {"Ale", {{"Rofii", 2}, {"Nanda", 2}, {"Agung", 1}}},
        {"Agung", {{"Ale", 1}}}
    };

    std::string start_dijkstra_node;
    std::string end_dijkstra_node;

    std::cout << "--- FITUR 1: Jalur Tercepat ---" << std::endl;
    std::cout << "Masukkan siswa asal: ";
    std::getline(std::cin, start_dijkstra_node);

    if (graph.find(start_dijkstra_node) == graph.end()) {
        std::cout << "Error: Siswa asal '" << start_dijkstra_node << "' tidak ditemukan dalam graf." << std::endl;
        return 1;
    }

    std::cout << "Masukkan siswa tujuan: ";
    std::getline(std::cin, end_dijkstra_node);

    if (graph.find(end_dijkstra_node) == graph.end()) {
        std::cout << "Error: Siswa tujuan '" << end_dijkstra_node << "' tidak ditemukan dalam graf." << std::endl;
        return 1;
    }

    runDijkstra(graph, start_dijkstra_node, end_dijkstra_node);

    std::cout << "\n--- FITUR 2: Semua Kemungkinan Pengiriman Pesan (Floyd-Warshall) ---" << std::endl;
    char cetak_matriks_choice;
    std::cout << "Cetak Matriks Jarak Terpendek (Y/T)? ";
    std::cin >> cetak_matriks_choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    bool print_matrix = (toupper(cetak_matriks_choice) == 'Y');

    std::string start_floyd_node;
    std::cout << "Masukkan siswa asal untuk Floyd-Warshall: ";
    std::getline(std::cin, start_floyd_node);

    if (graph.find(start_floyd_node) == graph.end()) {
        std::cout << "Error: Siswa asal '" << start_floyd_node << "' tidak ditemukan dalam graf." << std::endl;
        return 1;
    }

    runFloydWarshall(graph, start_floyd_node, print_matrix);

    return 0;
}

