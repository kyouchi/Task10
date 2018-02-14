// Task10.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "../FFT/fft.h"
#include "../generateWaveHelper/generateWave.h"
#include "../generateWaveHelper/ButterworthFilter.h"
#include "../GPlotTools/plot.h"


constexpr auto fs = 8192;//サンプリング周波数(2のべき乗)

//[in]question_number = 問題番号, [in] fm = 情報信号の周波数, [in] fc = キャリア周波数, [in] b =変調指数
void printTask10Answer(const unsigned int question_number, const unsigned int fm, const unsigned int fc, const double b)
{
   const auto graph_title = "waveform" + std::to_string(question_number) + "-";
   const auto graph_title_fft = "spectrum" + std::to_string(question_number) + "-";
   const auto file_name = "command" + std::to_string(question_number) + "-";
   const auto file_name_fft = "command_fft" + std::to_string(question_number) + "-";

   //情報信号
   GenerateWave graph1(fs, 0.5);
   graph1.generateSineWave(0.5, 1.0, fm);
   Plot(graph1.getGraph().x, graph1.getGraph().y, "t[sec]", "Amplitude", "Waveform", graph_title + "1.plt", file_name + "1.bat").executionPlot();
   //Plot(graph1.applyFft().x, graph1.applyFft().y, "f[Hz]", "Amplitude", "Apply FFT", graph_title_fft + "1.plt", file_name_fft + "1.bat").executionPlotAbs();

   //搬送波
   GenerateWave graph2(fs, 0.5);
   graph2.generateCarrierWave(fc, 1.0);
   Plot(graph2.getGraph().x, graph2.getGraph().y, "t[sec]", "Amplitude", "Waveform", graph_title + "2.plt", file_name + "2.bat").executionPlot();
   //Plot(graph2.applyFft().x, graph2.applyFft().y, "f[Hz]", "Amplitude", "Apply FFT", graph_title_fft + "2.plt", file_name_fft + "2.bat").executionPlotAbs();

   //FM変調
   GenerateWave graph3(fs, 0.5);
   graph3.generateFmWave(fc, b, graph1.getGraph());

   Plot(graph3.getGraph().x, graph3.getGraph().y, "t[sec]", "Amplitude", "Waveform", graph_title + "3.plt", file_name + "3.bat").executionPlot();
   Plot(graph3.applyFft().x, graph3.applyFft().y, "f[Hz]", "Amplitude", "Apply FFT", graph_title_fft + "3.plt", file_name_fft + "3.bat").executionPlotAbs();

   return;
}

int main()
{
   printTask10Answer(1, 50, 1000, 0.1);
   printTask10Answer(2, 50, 1000, 1);
   printTask10Answer(3, 50, 1000, 10);
   printTask10Answer(4, 50, 1000, 100);
   printTask10Answer(5, 25, 100, 1);
   return 0;
}
