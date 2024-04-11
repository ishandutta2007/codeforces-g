#include <bits/stdc++.h>
 
#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
 
#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()
 
#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB
 
using namespace std;
 
inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}
 
using ld = long double;
 
int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
	int n = nxt();
	long long k;
	scanf("%lld", &k);
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	ld r = 0;
	ld l = 0;
	for (int i = 0; i < n; ++i) {
		r = max<ld>(r, a[i]);
		l = min<ld>(l, a[i] - 3ll * a[i] * a[i]);
	}
	for (int it = 0; it < 300; ++it) {
		ld m = (l + r) / 2;
		ld sum = 0;
		for (int i = 0; i < n; ++i) {
			if (m > a[i]) {
				continue;
			}
			if (m < a[i] - 3ll * a[i] * a[i]) {
				sum += a[i];
				continue;
			}
			sum += sqrtl((a[i] - m) / 3);
		}
		if (sum >= k) {
			l = m;
		} else {
			r = m;
		}
	}
	vector<int> b(n);
	vector<pair<long long, int>> can;
	ld m = (l + r) / 2;
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		if (m > a[i]) {
			continue;
		}
		if (m < a[i] - 3ll * a[i] * a[i]) {
			k -= a[i];
			b[i] = a[i];
			ans += 1ll * b[i] * (a[i] - 1ll * b[i] * b[i]);
			continue;
		}
		b[i] = sqrtl((a[i] - m) / 3);
		k -= b[i];
		ans += 1ll * b[i] * (a[i] - 1ll * b[i] * b[i]);
		if (b[i] < a[i]) {
			can.push_back({1ll * (b[i] + 1) * (a[i] - 1ll * (b[i] + 1) * (b[i] + 1)) - 1ll * b[i] * (a[i] - 1ll * b[i] * b[i]), i});
		}
	}
	sort(all(can));
	while (k) {
		ans += can.back().first;
		b[can.back().second] += 1;
		can.pop_back();
		--k;
	}
 
	cerr << ans << "\n";
	for (int x : b) {
		cout << x << " ";
	}
	cout << "\n";
 
	return 0;
}// 
// 
// A56627DB45BC5E1B4C44AA72344F76B9
// A9F7727844F4F45F4E2BB07DFF6623F6
// 31FA7F38581F8CFE048828131891A9E3
// 975F5B0CF4A056A4B4959524710C59DD
// D53DC2AB0D8CC53A60826210120B49E9
// 06645C71FD2F612888D366C16123477D
// 90A26DD2AF2491D7E9570A822794B0E0
// 1C8E7290A762D3B85992CCD3B0A0E5C0
// DAC659462447D2983801396814F94578
// A41F623E04B3E3CB50F7C67870DFDA92
// 27AD6823E87EE939C96F6A33E22CAFC1
// 033940765375B2749927F7E9C17A4C1B
// 00538893414541254355921491DE9D44
// 87FE7674E1461D1A76A3A942677B5EB5
// 9628EBFC726949E2484413C7B105BF37
// F31B138A83C90937FEBD514A3C9AA92C
// E75306DFA5AA9226EFEBB8A3768A238E
// 49C1B3338C6C1BA2F343A9EC2C653296
// EB85C0143F446F29566D678F6614BD1D
// 583ECBFB4CB616CCC577D81B7A486806
// E03127123CED3048794D502D4F7CB3E9
// E017300189C92AF7E7341BAD814E3C41
// A11D9AFFC2D0BE2A3B9F5DB5D13989E8
// DC8467C3D52EBB49E6AA0B06329E26FF
// 58F2143AD75444582DD212E5EA86C9FE
// DB2A7752E071AB71A69D9669E7D090FC
// 235819ABECBD578548803E705AE25BEB
// AA05B60396FBC3A7A583669AFF0FA591
// BC19D99CB71DA833A481C97B2FDB1DA1
// 7364D88E09442C76F357583F332F429F
// 2F4FF183B2AA930463E45E049D1CCA59
// 3B4A146001B8A3C9E4652213EC73C272
// BFE345E4AA5D575151D2848F91068AC4
// DEB2514045989067C74EE06243E2E7ED
// 7496BE86464C1DBF816988EC9525E229
// 3AC09CD03C63C68DD2272786CAB93C39
// 433665F51BAAA63BFB05CBBEE5E82586
// 54DB27B66F1CCA9C1B673D37ADDA2218
// 3AF368EBD28AF4A5E3595846D6BE19EC
// 1587C72C0E3987447EE55D720557A800
// 03F29C9EC55E91DD5348C47E6FAD4581
// 2C3C8D30DFA8B61B4CB50B3CEFA1638E
// C3BB8451B400CEF3B1D4FE3F529E4893
// E1C03722E3CE2E107BEAA7EB206482D8
// BFCBD3B63540FC6A0B750663778C800F
// E2212B0A3690803A1F9D8F5A8BC1382E
// BBABA92D81AC92ABD95BC40A1D4FFD57
// 5F6A48526DE8DFE1035619956EFC07CD
// 2FCD8449340A018FF29C2EF766B759E5
// D11954D2FE1734240EFB3E7F4713803D
// 8CB963516E113862015E7025EDB5461B
// B9EC5DF97F063550FA7A612E4FD3451F
// DF3882A95F4F52E9AE97F367BA427716
// F00A91F76ACE7B22EB4A5AE3BC6D64D7
// 825888ECEBC90D064F9019674EB4E791
// 372061CF0D8627109E73B22A7201F2E9
// A4F09D5FA4B8AC1D2366BEC9810CE090
// 2CA41F399CA5CC2DF9290F2757A040DE
// 7803DF2CE6A665744F958CDDD749125D
// 353BB8E28FC6A346F7ECE02E620DE0A3
// 5391D8EBD92FD21F25095508BF3D5E8E
// 93521A05F4FE0795BB763805703FCA3A
// EC0CED880EDE3979F96E65E06D78C428
// 576C7714E7AAE06213AA0B50C80E4693
// 621DCBFBFE52F0C85465C5A7B75EBED8
// D672C1D170F9EF58EC021143813E0408
// 2D3B7CD7863A97BB2B1D1130A7DE1E9C
// 2E4530D7B43E79BF849CF5FE271F87DF
// A15B662E1F87A5ED3B816AA84B55CD69
// 2DA96F568C6D35EA1A3FC2198885B932
// 64EC7C96FC0CE6B757FBB2DFCF07A467
// 715C1B7F42B328CC3F7E24ADBE5AAD80
// 25DBDA98B5437F4429637237C781D94A
// FD13EBE06F2DE02ABAE1B19CB8D86D00
// B53196DC8591069B6D1423C5C54E164A
// 792A39AC20852632D4F71046C2D0AB27
// BB11CF89DEF2059C6D2E6A4FB28B8460
// 4DBBB54011A3C2498F0693B9B723A485
// 6EE7332B92F16368840B1C3AE5F86714
// 386EFEB6A81481E865DA1022E6CE1FBF
// 1A296149A6E8CF9A067A0DAB070BB297
// DCBAD10B47F9D7CFF927260571762273
// A17EDF66CC0039CC87EC16329B64CDB1
// 56CC09B0E4D7AF6D310B10264209B3F5
// 67E423AC1776FBB603447C468EE8CFAF
// 57A5A839554628F61D8C3EEB0A2196E4
// A44399218546866990789D4B9455FFB2
// 2942069FF1E98F5D2275113D22E46D66
// ED285E9916F751EDFB84F8EEF737F4D5
// 3CD90568042F4343A4571F0B720188A8
// A3F79BD858B9C272F55D91DA1C628CD2
// 0608863F1A9CB6E9360CE4D286C135D2
// 6DAA0FD532C9BD89444BE417258CECAD
// 239281E768513A22026071EC64B8D061
// 1C5ACE1B93B509BF8845B955DD2FF155
// 37B712D07793E892DBFBF371F6C1D31A
// BCEAA508F00ED8B69FDFA7EEDDBA7F91
// B3E4423B99A65BCF718FF27B85E1D5A9
// C7DF540C90607C2A1F4F1E6B02F6CF76
// 70286F4876B999CF36C003F2B47362D3
// D7B6722D73E7AF55CB6DE9D04B9626E3
// 1886D93BA4D81701F3E6FD742F79E9FE
// 04E29E4100967AED2A5B8647597335E0
// 879A60A703258BE6964EF3E13E2C315F
// D4DCF0B3BFEAE8E07658891C5ECEE274
// 5C9892F82E99FB66CC160B10D7B55B9E
// A967176164D2DEA08B9EE9D2E09F21E7
// 60B7763B5F2ABEA08508302AF9307879
// 1546ABEDE35AD5516AD75226BD173104
// 95B0FCB7E3276638301CAF9D38308BAD
// 89DB2972C028E2872CB8C9602BA4980B
// D938C4F1ED0972CD3742A4E195F2032B
// 79049A703B751A8E0F15E338CEC6E02C
// 0EC2EBE9BEBAD715A3F6D92C597BB97C
// 6D96E73CE2991E4C0527F807361155BC
// ED0107CA8F9A11526C70B0DB9E316974