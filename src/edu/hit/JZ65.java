package edu.hit;


/**
 * 矩形中的路径
 * <p>
 * 思路: 回溯
 */
public class JZ65 {

    // 访问标记数组
    private boolean[] visited;

    /**
     * @param matrix string字符串
     * @param rows   int整型
     * @param cols   int整型
     * @param str    string字符串
     * @return bool布尔型
     */
    public boolean hasPath(String matrix, int rows, int cols, String str) {
        visited = new boolean[matrix.length()];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (judge(matrix, str, rows, cols, i, j, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean judge(String matrix, String str, int rows, int cols, int rowIndex, int colIndex, int indexInStr, boolean[] visited) {

        // 当前矩阵字符串的访问位置
        int indexInMatrix = rowIndex * cols + colIndex;

        // 不匹配的情况
        if (rowIndex < 0 || colIndex < 0 || rowIndex >= rows ||
                colIndex >= cols || visited[indexInMatrix] == true ||
                matrix.charAt(indexInMatrix) != str.charAt(indexInStr)) {
            return false;
        }

        // 标记为已访问
        visited[indexInMatrix] = true;

        if(indexInStr == str.length() - 1){
            return true;
        }

        // 判断上下左右四个方向
        if(judge(matrix,str,rows,cols,rowIndex - 1,colIndex,indexInStr + 1,visited) ||
                judge(matrix,str,rows,cols,rowIndex + 1,colIndex,indexInStr + 1,visited) ||
                judge(matrix,str,rows,cols,rowIndex,colIndex - 1,indexInStr + 1,visited) ||
                judge(matrix,str,rows,cols,rowIndex,colIndex + 1,indexInStr + 1,visited)){
            return true;
        }

        // 重置为未访问
        visited[indexInMatrix] = false;
        return false;
    }

    public static void main(String[] args) {
        JZ65 jz65 = new JZ65();
        System.out.println(jz65.hasPath("ABCESFCSADEE",3,4,"SEE"));
    }
}
