import java.io.*
import java.util.*

object Main {
    var `in`: IO? = null
    var out: PrintWriter? = null

    @Throws(Exception::class)
    fun init_io(filename: String) {
        if (filename == "") {
            `in` = IO(System.`in`)
            out = PrintWriter(BufferedWriter(OutputStreamWriter(System.out)), true)
        } else {
            `in` = IO(FileInputStream("$filename.in"))
            out = PrintWriter(BufferedWriter(FileWriter("$filename.out")), true)
        }
    }

    const val mod: Long = 1000000007

    /*
fun main(args: Array<String>) {
    Main.main(args);
}
*/
    /* todo list
- stick main snippet at bottom
- remove "internal" from IO class (and all static classes)
- remove question marks (?) from comparable stuff (ex: <Edge?> -> <Edge>)
*/
    var cnt = 0
    var n = 0
    var m = 0
    var dr = intArrayOf(-1, 0, 1, 0)
    var dc = intArrayOf(0, -1, 0, 1)
    var tour: ArrayList<Int>? = null
    fun dfs(r: Int, c: Int, g: Array<IntArray>, vis: Array<BooleanArray>) {
        if (vis[r][c]) return
        tour!!.add(g[r][c])
        vis[r][c] = true
        --cnt
        for (d in 0..3) {
            val nr = r + dr[d]
            val nc = c + dc[d]
            if (0 <= nr && nr < n && 0 <= nc && nc < m) {
                if (g[nr][nc] != 0 && !vis[nr][nc]) {
                    dfs(nr, nc, g, vis)
                    tour!!.add(g[r][c])
                }
            }
        }
    }

    @Throws(Exception::class)
    fun solve(tc: Int) {
        n = `in`!!.nint()
        m = `in`!!.nint()
        cnt = 0
        val g = Array(n) { IntArray(m) }
        val vis = Array(n) { BooleanArray(m) }
        for (i in 0 until n) {
            for (j in 0 until m) {
                g[i][j] = `in`!!.nint()
                if (g[i][j] != 0) ++cnt
            }
        }
        val rcnt = cnt
        tour = ArrayList()
        for (i in 0 until n) {
            for (j in 0 until m) {
                if (g[i][j] != 0) {
                    dfs(i, j, g, vis)
                    break
                }
            }
            if (cnt < rcnt) break
        }
        if (cnt != 0) {
            out!!.println(-1)
        } else {
            out!!.println("$rcnt $rcnt")
            val grid = Array(rcnt) { IntArray(rcnt) }
            for (i in 0 until rcnt) {
                for (k in 0..i) {
                    grid[i - k][k] = tour!![i]
                }
            }
            for (j in 1 until rcnt) {
                for (k in 0 until rcnt - j) {
                    grid[rcnt - 1 - k][j + k] = tour!![rcnt + j - 1]
                }
            }
            for (i in 0 until rcnt) {
                for (j in 0 until rcnt) {
                    out!!.print(grid[i][j].toString() + " ")
                }
                out!!.println()
            }
        }
    }

    @Throws(Exception::class)
    @JvmStatic
    fun main(_u_n_u_s_e_d_: Array<String>) {
        init_io("")
        var t = 1
        t = `in`!!.nint()
        for (tc in 0 until t) {
            solve(tc)
        }
    }

    fun minv(v: Long): Long {
        return mpow(v, mod - 2)
    }

    fun mpow(base: Long, exp: Long): Long {
        var base = base
        var exp = exp
        var res: Long = 1
        while (exp > 0) {
            if (exp and 1 == 1L) {
                res = res * base % mod
            }
            base = base * base % mod
            exp = exp shr 1
        }
        return res
    }

    fun gcd(x: Int, y: Int): Int {
        if (x == 0) return y
        return if (y == 0) x else gcd(y % x, x)
    }

    fun rsort(arr: LongArray) {
        val r = Random()
        for (i in arr.indices) {
            val j = i + r.nextInt(arr.size - i)
            val t = arr[i]
            arr[i] = arr[j]
            arr[j] = t
        }
        Arrays.sort(arr)
    }

    fun rsort(arr: IntArray) {
        val r = Random()
        for (i in arr.indices) {
            val j = i + r.nextInt(arr.size - i)
            val t = arr[i]
            arr[i] = arr[j]
            arr[j] = t
        }
        Arrays.sort(arr)
    }

    /* static void qsort(long[] arr) {
    Long[] oarr = new Long[arr.length];
    for (int i = 0; i < arr.length; i++) {
      oarr[i] = arr[i];
    }
 
    ArrayList<Long> alist = new ArrayList<Long>(Arrays.asList(oarr));
    Collections.sort(alist);
 
    for (int i = 0; i < arr.length; i++) {
      arr[i] = (long)alist.get(i);
    }
  } */
    fun reverse(arr: LongArray) {
        for (i in 0 until arr.size / 2) {
            val temp = arr[i]
            arr[i] = arr[arr.size - 1 - i]
            arr[arr.size - 1 - i] = temp
        }
    }

    fun atos(arr: LongArray?): String {
        var s = Arrays.toString(arr)
        s = s.substring(1, s.length - 1)
        return s.replace(",", "")
    }

     class IO(x: InputStream?) {
        var `in`: BufferedReader
        var tokens: StringTokenizer

        @Throws(Exception::class)
        fun nint(): Int {
            return nstr().toInt()
        }

        @Throws(Exception::class)
        fun nlong(): Long {
            return nstr().toLong()
        }

        @Throws(Exception::class)
        fun ndouble(): Double {
            return nstr().toDouble()
        }

        @Throws(Exception::class)
        fun nstr(): String {
            if (!tokens.hasMoreTokens()) tokens = StringTokenizer(`in`.readLine())
            return tokens.nextToken()
        }

        @Throws(Exception::class)
        fun nla(n: Int): LongArray {
            val arr = LongArray(n)
            for (i in 0 until n) {
                arr[i] = nlong()
            }
            return arr
        }

        init {
            `in` = BufferedReader(InputStreamReader(x))
            tokens = StringTokenizer(`in`.readLine())
        }
    } // static class Pair<A extends Comparable<A>, B extends Comparable<B>> implements Comparable<Pair<A, B>> {
    // public A f;
    // public B s;
    // public Pair(A a, B b) {
    // f = a;
    // s = b;
    // }
    // public int compareTo(Pair<A, B> other) {
    // int v = f.compareTo(other.f);
    // if (v != 0) return v;
    // return s.compareTo(other.s);
    // }
    // public String toString() {
    // return "(" + f.toString() + ", " + s.toString() + ")";
    // }
    // }
}fun main(args: Array<String>) {
    Main.main(args);
}