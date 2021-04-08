package edu.hit;


/**
 * 矩形中的路径
 * <p>
 * 思路: 回溯
 */
public class JZ65 {

    // 访问标记数组
    private boolean[][] visited;

    public boolean hasPath (char[][] matrix, String word) {
        int rows = matrix.length;
        int cols = matrix[0].length;

        visited = new boolean[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (judge(matrix, word, rows, cols, i, j, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }


    private boolean judge(char[][] matrix, String word, int rows, int cols, int rowIndex, int colIndex, int indexInWord, boolean[][] visited) {

        // 不匹配的情况
        if (rowIndex < 0 || colIndex < 0 || rowIndex >= rows ||
                colIndex >= cols || visited[rowIndex][colIndex] == true ||
                matrix[rowIndex][colIndex] != word.charAt(indexInWord)) {
            return false;
        }

        // 标记为已访问
        visited[rowIndex][colIndex] = true;

        if(indexInWord == word.length() - 1){
            return true;
        }

        // 判断上下左右四个方向
        if(judge(matrix,word,rows,cols,rowIndex - 1,colIndex,indexInWord + 1,visited) ||
                judge(matrix,word,rows,cols,rowIndex + 1,colIndex,indexInWord + 1,visited) ||
                judge(matrix,word,rows,cols,rowIndex,colIndex - 1,indexInWord + 1,visited) ||
                judge(matrix,word,rows,cols,rowIndex,colIndex + 1,indexInWord + 1,visited)){
            return true;
        }

        // 重置为未访问
        visited[rowIndex][colIndex] = false;
        return false;
    }

    public static void main(String[] args) {
        JZ65 jz65 = new JZ65();
        char[][] ch = {{'a','b','c','e'},{'s','f','c','s'},{'a','d','e','e'}};
        System.out.println(jz65.hasPath(ch,"abcced"));
    }
}
