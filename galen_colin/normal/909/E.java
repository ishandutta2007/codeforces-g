import java.io.*;
import java.util.*;

public class Main {
  public static IO in;
  public static PrintWriter out;

  static void init_io(String filename) throws Exception {
    if (filename.equals("")) {
      in = new IO(System.in);
      out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)), true);
    } else {
      in = new IO(new FileInputStream(filename + ".in"));
      out = new PrintWriter(new BufferedWriter(new FileWriter(filename + ".out")), true);
    }
  }

  final static long mod = 1_000_000_007;

  public static void main(String[] _u_n_u_s_e_d_) throws Exception {
    init_io("");

    ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>();
    int ans = 0;

    int n = in.nint(), m = in.nint();
    for (int i = 0; i < n; i++) {
      graph.add(new ArrayList<Integer>());
    }

    boolean[] c = new boolean[n];
    int[] ideg = new int[n];

    for (int i = 0; i < n; i++) {
      int x = in.nint();

      if (x == 1) c[i] = true;
    }

    for (int i = 0; i < m; i++) {
      int a = in.nint(), b = in.nint();

      graph.get(b).add(a);
      ++ideg[a];
    }    

    ArrayDeque<Integer> z = new ArrayDeque<Integer>();
    ArrayDeque<Integer> o = new ArrayDeque<Integer>();

    for (int i = 0; i < n; i++) {
      if (ideg[i] == 0) {
        if (c[i] == false) {
          z.add(i);
        } else {
          o.add(i);
        }
      }
    }

    while (z.size() > 0 || o.size() > 0) {
      if (z.size() > 0) {
        while (z.size() > 0) {
          int x = z.poll();
          for (int y: graph.get(x)) {
            --ideg[y];
            if (ideg[y] == 0) {
              if (c[y] == false) {
                z.add(y);
              } else {
                o.add(y);
              }
            }
          }
        }
      } else {
        while (o.size() > 0) {
          int x = o.poll();
          for (int y: graph.get(x)) {
            --ideg[y];
            if (ideg[y] == 0) {
              if (c[y] == false) {
                z.add(y);
              } else {
                o.add(y);
              }
            }
          }
        }
        ++ans;
      }
    }

    out.println(ans);
  }

  static int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
  }

  static void qsort(long[] arr) {
    Long[] oarr = new Long[arr.length];
    for (int i = 0; i < arr.length; i++) {
      oarr[i] = arr[i];
    }

    ArrayList<Long> alist = new ArrayList<Long>(Arrays.asList(oarr));
    Collections.sort(alist);

    for (int i = 0; i < arr.length; i++) {
      arr[i] = alist.get(i);
    }
  }

  static void reverse(long[] arr) {
    for (int i = 0; i < arr.length / 2; i++) {
      long temp = arr[i];
      arr[i] = arr[arr.length - 1 - i];
      arr[arr.length - 1 - i] = temp;
    }
  }

  static String atos(long[] arr) {
    String s = Arrays.toString(arr);
    s = s.substring(1, s.length() - 1);
    return s.replace(",", "");
  }

  static class IO {
    public BufferedReader in;
    public StringTokenizer tokens;

    public IO(InputStream x) throws Exception {
      in = new BufferedReader(new InputStreamReader(x));
      tokens = new StringTokenizer(in.readLine());
    }

    int nint() throws Exception {
      return Integer.parseInt(nstr());
    }

    long nlong() throws Exception {
      return Long.parseLong(nstr());
    }

    double ndouble() throws Exception {
      return Double.parseDouble(nstr());
    }

    String nstr() throws Exception {
      if (!tokens.hasMoreTokens()) tokens = new StringTokenizer(in.readLine());
      return tokens.nextToken();
    }
    
    long[] nla(int n) throws Exception {
      long[] arr = new long[n];
      for (int i = 0; i < n; i++) {
        arr[i] = nlong();
      }
      return arr;
    }
  }

  static class Pair<A extends Comparable<A>, B extends Comparable<B>> implements Comparable<Pair<A, B>> {
    public A f;
    public B s;

    public Pair(A a, B b) {
      f = a;
      s = b;
    }

    public int compareTo(Pair<A, B> other) {
      int v = f.compareTo(other.f);
      if (v != 0) return v;
      return s.compareTo(other.s);
    }

    public String toString() {
      return "(" + f.toString() + ", " + s.toString() + ")";
    }
  }
}