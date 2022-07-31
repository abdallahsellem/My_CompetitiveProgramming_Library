 memset(dis, '?', sizeof dis);
  for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dis[i][k] == INT_MAX || dis[k][j] == INT_MAX) {
                        continue;
                    }
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }