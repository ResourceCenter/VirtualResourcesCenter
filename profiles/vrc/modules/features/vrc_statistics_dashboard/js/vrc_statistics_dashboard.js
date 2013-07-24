(function($) {

  Drupal.behaviors.vrcStatisticsDashboard = {
    attach : function(context, settings) {
      var xAxisValues = [];
      var padXAxisValues = [];
      for ( var i = 0; i < 10; i++) {
        var date = new Date();
        date.setDate(date.getDate() + i);
        if (i == 0 || i == 10) {
          padXAxisValues.push(date.getTime());
        } else {
          xAxisValues.push(date.getTime());
        }
      }

      /*************************************************************************
       * HELPER FUNCTIONS
       ************************************************************************/
      function getRandomColor() {
        var colors = Highcharts.getOptions().colors;
        return colors[Math.floor(Math.random() * colors.length)];
      }

      // A function to dynamicly generate the chart
      Highcharts.Chart.prototype.setChart = function setChart(name, categories, data, color, level) {
        this.xAxis[0].setCategories(categories, false);
        this.series[0].remove(false);
        this.addSeries({
          name : name,
          data : data,
          level: level,
          color : color || 'white'
        }, false);
        this.redraw();
      }

      function getMonthSummary(data) {
        var _data = _(data).filter(function(item) {
          return 'object' === typeof item && item.total;
        });
        return _(_data).pluck('total');
      }

      function getMonthName(month, abbrev) {
        month = month - 1;
        abbrev = (typeof abbrev !== 'undefined') ? abbrev : true;
        var shortNames = ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec'];
        var longNames = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December'];
        return abbrev ? shortNames[month] : longNames[month];
      }

      function convertToMonthNames(months) {
        _months = _(months).map(function(value, key, list) {
          return getMonthName(value);
        });
        return _months;
      }

      //------------------------------------------------------------------------
      // HIGHCHART CHART - REGISTERED USER
      //
      // Here are some examples on triple drill down
      // @see http://jsfiddle.net/zaheerahmed/7xEhW/
      //------------------------------------------------------------------------

      if ($('#vrc_sd_registered_users_dr').length > 0) {
        vrc_sd_draw_registered_users_count_chart();
      }

      function vrc_sd_draw_registered_users_count_chart() {
        // Prepare the chart data
        var dataRaw = settings.vrc_highcharts.vrc_sd_registered_users_dr.data;
        var dataSummaryRaw = settings.vrc_highcharts.vrc_sd_registered_users_dr.dataSummary;

        // Initially, year summary
        var colors = Highcharts.getOptions().colors;
        var name = 'View by year';
        var categories = _.keys(dataRaw);
        var level = 0;
        var data = [];

        $i = 0;
        _.each(dataRaw, function(yearValue, yearKey, list) {
          // Prepare the data for the top level (year summary view)
          var yearData = {};
          yearData.y = dataSummaryRaw[yearKey]['total'];
          yearData.color = colors[$i];
          yearData.drilldown = {};
          yearData.drilldown.level = 1;
          yearData.drilldown.name = 'Year ' + yearKey;
          // @todo: Convert this into month abbrev names
          yearData.drilldown.categories = convertToMonthNames(_(yearValue).keys());
          yearData.drilldown.color = colors[$i];
          yearData.drilldown.data = [];
          // Prepare data for the second level drill down (month summary view)
          _.each(yearValue, function(monthValue, monthKey, list) {
            monthData = {};
            monthData.y = dataSummaryRaw[yearKey][monthKey]['total'];
            monthData.color = colors[$i];

            // Prepare data for the third level drill down (day summary view)
            monthData.drilldown = {};
            monthData.drilldown.name = getMonthName(monthKey) + ', ' +  yearKey;
            monthData.drilldown.categories = _(monthValue).keys();
            monthData.drilldown.data = _(monthValue).values();
            monthData.drilldown.level = 2;
            monthData.drilldown.color = colors[$i];

            yearData.drilldown.data.push(monthData);
          });
          data.push(yearData);
          $i++;
        });

        // Initialize the chart
        var chart = new Highcharts.Chart({
          chart : {
            renderTo : 'vrc_sd_registered_users_dr',
            type : 'column'
          },
          title : {
            text : 'Number of Registered Users'
          },
          subtitle : {
            text : 'Click the columns to view detail, and click again to view summary.'
          },
          xAxis : {
            categories : categories
          },
          yAxis : {
            title : {
              text : 'Number of users registered'
            }
          },
          plotOptions : {
            column : {
              cursor : 'pointer',
              point : {
                events : {
                  click : function() {
                    var drilldown = this.drilldown;
                    // drill down
                    if (drilldown) {
                      chart.setChart(drilldown.name, drilldown.categories, drilldown.data, drilldown.color, drilldown.level);
                    }
                    // restore
                    else {
                      chart.setChart(name, categories, data, null, level);
                    }
                  }
                }
              },
              dataLabels : {
                enabled : true,
                color : colors[0],
                style : {
                  fontWeight : 'bold'
                },
                formatter : function() {
                  return this.y;
                }
              }
            }
          },
          tooltip : {
            formatter : function() {
              var point = this.point;
              var text = '';
              switch(this.series.options.level) {
              case 0:
                text = 'In ' + this.x + ', <b>' + this.y + '</b> users registerd<br/>';
                text += '<em>Click to view by month.</em>';
                break;
              case 1:
                text = 'In ' + this.x + ', <b>' + this.y + '</b> users registerd<br/>';
                text += '<em>Click to view by day.</em>';
                break;
              case 2:
                text = 'On ' + this.x + ', <b>' + this.y + '</b> users registered<br/>';
                text += 'Click to return to view by year.';
                break;
              }
              return text;
            }
          },
          series : [ {
            name : name,
            level: level,
            data : data,
            color : 'white'
          } ],
          legend: {
            // Only one series, no need for this
            // enabled : false,
          },
          exporting : {
            enabled : false
          },
          credits : {
            enabled : false
          }
        });// end of chart initializing
      }

      //------------------------------------------------------------------------
      //  NUMBER OF VOTES ON THE SITE
      //------------------------------------------------------------------------
      function vrc_sd_draw_site_votes_count_chart() {
        var container = 'vrc_sd_site_votes_count_chart';
        var dataRaw = settings.vrc_highcharts.vrc_sd_site_votes_count.data;
        var options = {
          chart : {
            renderTo : container,
            type : 'line',
            marginBottom : 80,
          },
          title : {
            text : 'Number of votes on the platform <em>(Last 30 days)</em>',
            x : -20
          // center
          },
          subtitle : {
            // text : '(last 30 days)',
            // x : -20
          },
          xAxis : {
            labels: {
              rotation: -45,
              align: 'right',
              style: {
                fontSize: '8px',
                fontFamily: 'Verdana, sans-serif',
                color: '#666',
              }
            }
          },
          yAxis : {
            title : {
              text : 'Number of votes'
            },
            plotLines : [ {
              value : 0,
              width : 1,
              color : '#808080'
            } ]
          },
          tooltip : {
            formatter : function() {
              var text = '';
              if (this.y) {
                text = '<b>' + this.y + '</b> votes';
              }
              else {
                text = 'no vote';
              }
              return 'On <b>' + this.x + '</b>' + ', ' + text;
            }
          },
          legend: {
            // Only one series, no need for this
            // enabled : false,
          },
          series : [],
          credits : {
            enabled : false
          }
        };

        // Use the short date name as the x-axis labels
        options.xAxis.categories = _(dataRaw).pluck('name_short');
        var serie = {};
        serie.data = _(dataRaw).pluck('count');
        //serie.color = getRandomColor();
        //console.log(serie.color);
        serie.color = '#3D96AE';
        serie.name = 'Vote count per day';
        options.series.push(serie);

        var chartNumberOfVotes = new Highcharts.Chart(options);
      }

      if ($('#vrc_sd_site_votes_count_chart').length > 0) {
        vrc_sd_draw_site_votes_count_chart();
      }

     //------------------------------------------------------------------------
     //  HIGHCHART CHART - NUMBER OF SEARCHES PERFORMED
     //------------------------------------------------------------------------
      function vrc_sd_search_performed_count_chart() {
        var container = 'vrc_sd_search_performed_count_chart';
        var dataRaw = settings.vrc_highcharts.vrc_sd_search_performed_count.data;
        var options = {
            chart : {
              renderTo : container,
              type : 'line',
              marginBottom : 80,
            },
            title : {
              text : 'Number of Searches Performed <em>(Last 30 Days)</em>',
              x : -20
              // center
            },
            subtitle : {
              // text : '(last 30 days)',
              // x : -20
            },
            xAxis : {
              labels: {
                rotation: -45,
                align: 'right',
                style: {
                  fontSize: '8px',
                  fontFamily: 'Verdana, sans-serif',
                  color: '#666',
                }
              }
            },
            yAxis : {
              title : {
                text : 'Number of searches'
              },
              plotLines : [ {
                value : 0,
                width : 1,
                color : '#808080'
              } ]
            },
            tooltip : {
              formatter : function() {
                var text = '';
                if (this.y) {
                  text = '<b>' + this.y + '</b> times';
                }
                else {
                  text = 'no search';
                }
                return 'On <b>' + this.x + '</b>' + ', ' + text;
              }
            },
            series : [],
            legend: {
              // Only one series, no need for this
              // enabled : false,
            },
            credits : {
              enabled : false
            }
        };

        // Use the short date name as the x-axis labels
        options.xAxis.categories = _(dataRaw).pluck('name_short');
        var serie = {};
        serie.data = _(dataRaw).pluck('count');
        serie.name = 'Seaches performed per day';
        //serie.color = getRandomColor();
        serie.color = '#AA4643';
        options.series.push(serie);

        var chartNumberOfSearch = new Highcharts.Chart(options);
      }

      if ($('#vrc_sd_search_performed_count_chart').length > 0) {
        vrc_sd_search_performed_count_chart();
      }

      //------------------------------------------------------------------------
      //  HIGHCHART CHART - NUMBER OF ARTICLES
      //------------------------------------------------------------------------
      function vrc_sd_article_posted_number_chart() {
        var colors = Highcharts.getOptions().colors;
        var dataRaw = settings.vrc_highcharts.vrc_sd_article_posted_number.data;

        // The top level's categories are the day names
        var categories = _(dataRaw).pluck('name_short');
        var name = 'Number of Articles posted';

        // A callback use to redraw the chart
        function setChartNumberOfArticles(options) {
          chartNumberOfArticles.series[0].remove(false);
          chartNumberOfArticles.addSeries({
            type : options.type,
            name : options.name,
            data : options.data,
            color : options.color || 'white'
          }, false);

          if (options.type == 'pie') {
            chartNumberOfArticles.xAxis[0].setCategories([], false);
          }
          else {
            chartNumberOfArticles.xAxis[0].setCategories(options.categories, false);
          }
          chartNumberOfArticles.redraw();
        }

        /**
         * Callback
         */
        function pickCountAndTermName(obj) {
          return _.map(obj.articles.by_category, function(value){
            return [value['term_name'], value['count']];
          });
        }

        var data = [];
        // Prepare the data, the first level elements is the newly created
        // article count by the day
        _.each(dataRaw, function(dayValue, dayTimestamp, list) {
          var dayData = {};
          dayData.y = dayValue.articles.count;
          dayData.color = colors[0];
          dayData.drilldown = {};
          dayData.drilldown.name = dayValue.name_short;
          // The categories of the second level should be the category term's names
          dayData.drilldown.data = pickCountAndTermName(dayValue);
          data.push(dayData);
        });

        var chartNumberOfArticles = new Highcharts.Chart({
          chart : {
            renderTo : 'vrc_sd_article_posted_number_chart',
            plotBackgroundColor: null,
            plotBorderWidth: null,
          },
          title : {
            text : 'Number of Article Posted with Breakdown by Taxonomy <em>(last 30 days)</em>'
          },
          subtitle : {
            text : 'Click the column to view count breakdown by taxonomies. Click again to view by days.'
          },
          xAxis : {
            categories : categories,
            labels : {
              enabled: true,
              rotation : -45,
              align : 'right',
              style : {
                fontSize : '8px',
                fontFamily : 'Verdana, sans-serif',
                color : '#666',
              }
            }
          },
          yAxis : {
            title : {
              text : 'Number of articles'
            }
          },
          plotOptions : {
            series : {
              colorByPoint: true,
              cursor : 'pointer',
              point : {
                events : {
                  click : function() {
                    var drilldown = this.drilldown;
                    var options;
                    // drill down
                    if (drilldown) {
                      options = {
                        'type' : 'pie',
                        'name' : drilldown.name,
                        'categories' : drilldown.categories,
                        'data' : drilldown.data,
                        'color' : drilldown.color,
                      };
                    }
                    // restore
                    else {
                      options = {
                        'type' : 'column',
                        'name' : name,
                        'categories' : categories,
                        'data' : data,
                      };
                    }
                    setChartNumberOfArticles(options);
                  }
                }
              },
              dataLabels : {
                enabled : true,
                color : colors[0],
                style : {
                  // fontWeight : 'bold'
                },
                formatter : function() {
                  if (this.series.options.type == 'pie') {
                    return this.point.name + ': <strong>' + this.y + '</strong><em>(' + Math.round(this.percentage) + '%)</em>';
                  }
                  else {
                    return this.y;
                  }
                  console.log(this);
                }
              }
            },
          },
          tooltip : {
            formatter : function() {
              var point = this.point;
              var text = '';
              if (point.drilldown) {
                text += this.x + ':<b>' + this.y + ' new articles</b><br/>';
                text += 'Click to view breakdown by category';
              } else {
                text += '<b>' + this.y + '</b> new articles in <em>' + this.key + '</em><br/>'
                text += 'Click to return to daily count';
              }
              return text;
            }
          },
          series : [ {
            type : 'column',
            name : name,
            data : data,
          } ],
          legend: {
            // Only one series, no need for this
            // enabled : false,
          },
          exporting : {
            enabled : false
          },
          credits : {
            enabled : false
          }
        });
      }

      if ($('#vrc_sd_article_posted_number_chart').length > 0) {
        vrc_sd_article_posted_number_chart();
      }

      //------------------------------------------------------------------------
      //  HIGHCHART CHART - NUMBER OF QUESTIONS
      //------------------------------------------------------------------------
      function vrc_sd_draw_question_posted_number_chart() {
        var colors = Highcharts.getOptions().colors;
        var dataRaw = settings.vrc_highcharts.vrc_sd_question_posted_number.data;

        var data = [];
        // Prepare the data, the first level elements is the article count by
        // the day
        _.each(dataRaw, function(dayValue, dayTimestamp, list) {
          var dayData = {};
          dayData.y = dayValue.questions.count;
          dayData.color = colors[0];
          dayData.drilldown = {};
          // The drilldown should contains two pie chart, sound a little tricky
          // here. Two pie charts!

          var byCategory = {};
          var byTool = {};
          // So prepare one object for each
          byCategory.type = 'pie';
          byCategory.name = 'Breakdown by Category';
          byCategory.data = _.map(dayValue.questions.by_category, function(value) {
            return [value['term_name'], value['count']]
          });
          dayData.drilldown.byCategory = byCategory;

          byTool.type = 'pie';
          byTool.name = 'Breakdown by Tool';
          byTool.data = _.map(dayValue.questions.by_tool, function(value) {
            return [value['term_name'], value['count']]
          });
          dayData.drilldown.byTool = byTool;
          data.push(dayData);
        });

        console.log(data);

        var categories = _(dataRaw).pluck('name_short');
        var name = 'Number of Questions Asked';

        var chartNumberOfQuestions = new Highcharts.Chart({
          chart : {
            renderTo : 'vrc_sd_question_posted_number_chart',
            plotBackgroundColor: null,
            plotBorderWidth: null,
          },
          title : {
            text : 'Number of Questions Asked with Breakdown by Taxonomy and Categories <em>(last 30 days)</em>'
          },
          subtitle : {
            text : 'Click the column to see count breakdown by categories. Click again to view by days.'
          },
          xAxis : {
            categories : categories,
            labels : {
              enabled : true,
              rotation : -45,
              align : 'right',
              style : {
                fontSize : '8px',
                fontFamily : 'Verdana, sans-serif',
                color : '#666',
              },
            }
          },
          yAxis : {
            title : {
              text : 'Number of questions'
            }
          },
          plotOptions : {
            series : {
              cursor : 'pointer',
              point : {
                events : {
                  click : function() {
                    console.log(this.drilldown);
                    var drilldown = this.drilldown;
                    var opts;
                    // drill down
                    if (drilldown) {
                      opts = {
                        'mixed' : drilldown,
                      };
                    }
                    // restore
                    else {
                      opts = {
                        'type' : 'column',
                        'name' : name,
                        'categories' : categories,
                        'data' : data,
                      };
                    }

                    setChartNumberOfQuestion(opts);
                  }
                }
              },
              dataLabels : {
                enabled : true,
                color : colors[0],
                style : {
                  // fontWeight : 'bold'
                },
                formatter : function() {
                  if (this.series.options.type == 'pie') {
                    return this.point.name + ': <strong>' + this.y + '</strong><em>(' + Math.round(this.percentage) + '%)</em>';
                  }
                  else {
                    return this.y;
                  }
                  console.log(this);
                }
              }
            },
          },
          tooltip : {
            formatter : function() {
              var point = this.point;
              var s = this.x + ':<b>' + this.y + ' new articles</b><br/>';

              if (point.drilldown) {
                s += 'Click to view ' + point.category + ' by category';
              } else {
                s += 'Click to return to daily count';
              }
              return s;
            }
          },
          series : [ {
            type : 'column',
            name : name,
            data : data,
            color : 'white'
          } ],
          legend: {
            // Only one series, no need for this
            // enabled : false,
          },
          exporting : {
            enabled : false
          },
          credits : {
            enabled : false
          }
        });

        /**
         * Helper function to help the drilldown by Category and Tool terms
         */
        function setChartNumberOfQuestion(options) {
          console.log(options);
          // No matter what, we are gonna clear the previous chart during switch
          for(var i = 0; i < chartNumberOfQuestions.series.length; i++){
            // chartNumberOfQuestions.series[i].remove();
            // console.log(chartNumberOfQuestions.series[i]);
          }

          // Handle the drilldown double pie charts
          // When the user is drilling down a column's data
          if (options.mixed && options.mixed.byCategory && options.mixed.byTool) {
            console.log(data);
            chartNumberOfQuestions.xAxis[0].setCategories(["Awesome"]);

            // Remove the first series, and postpone the redraw
            for(var i = 0; i < chartNumberOfQuestions.series.length; i++){
              // chartNumberOfQuestions.series[i].remove();
              // Hope we can hide the remaining the grid and axis labels here
              if (chartNumberOfQuestions.series[i].visible) {
                chartNumberOfQuestions.series[i].hide();
                $(chartNumberOfQuestions.series[i].data).each(function(i, e) {
                  // e.graphic.hide();
                  // e.dataLabel.hide();
                  // e.connector.hide();
                });
              }
              chartNumberOfQuestions.series[i].remove();
            }

            _.each(options.mixed, function(item, key, list) {
              var options = {};
              options.name = item.name;
              options.data = item.data;
              options.type = item.type;
              options.color = item.color || 'white';

              if (key == 'byCategory') {
                options.center = [300, 160];
              }
              else if (key == 'byTool') {
                options.center = [800, 160];
              }
              else {
                 //
              }
              chartNumberOfQuestions.addSeries(options, false);
            });
            chartNumberOfQuestions.redraw();
            // Change the title
//            chartNumberOfQuestions.setTitle(
//              {text:'New main title'}
//            );
          }
          // Handle the top level column chart
          else {
            console.log(data);
            // When switched from the double pie charts to the column chart,
            // there are more that one series on the chart
            _.each(chartNumberOfQuestions.series, function(item, index, list) {
              chartNumberOfQuestions.series[index].remove();
            });
            _.each(chartNumberOfQuestions.series, function(item, index, list) {
              chartNumberOfQuestions.series[index].remove();
            });
            for(var i = 0; i < chartNumberOfQuestions.series.length; i++){
              chartNumberOfQuestions.series[i].remove();
              // console.log(chartNumberOfQuestions.series[i]);
            }

            chartNumberOfQuestions.addSeries({
              type : 'column',
              name : name,
              data : data,
              color : options.color || 'white'
            }, false);

//            type : 'column',
//            name : name,
//            data : data,
//            color : 'white'

            if (options.type == 'pie') {
              chartNumberOfQuestions.xAxis[0].setCategories([], false);
            }
            else {
              chartNumberOfQuestions.xAxis[0].setCategories(options.categories, false);
            }
            chartNumberOfQuestions.redraw();
          }
        }
      }
      if ($('#vrc_sd_question_posted_number_chart').length > 0) {
        vrc_sd_draw_question_posted_number_chart();
      }

      //------------------------------------------------------------------------
      //  HIGHCHART CHART - NUMBER OF ANSWERS
      //------------------------------------------------------------------------
      function vrc_sd_draw_answer_posted_number_chart() {
        var colors = Highcharts.getOptions().colors;
        var dataRaw = settings.vrc_highcharts.vrc_sd_answer_posted_number.data;

        // The top level categories are the day names
        var categories = _(dataRaw).pluck('name_short');
        var name = 'Number of Answers Posted';

        // A callback use to redraw the chart
        function setChartNumberOfAnswers(options) {
          chartNumberOfAnswers.series[0].remove(false);
          chartNumberOfAnswers.addSeries({
            type : options.type,
            name : options.name,
            data : options.data,
            color : options.color || 'white'
          }, false);

          if (options.type == 'pie') {
            chartNumberOfAnswers.xAxis[0].setCategories([], false);
          }
          else {
            chartNumberOfAnswers.xAxis[0].setCategories(options.categories, false);
          }
          chartNumberOfAnswers.redraw();
        }

        /**
         * Callback
         */
        function pickCountAndQuestionTitle(obj) {
          return _.map(obj.answers.by_question, function(value){
            return [value['question_title'], value['count']];
          });
        }

        var data = [];
        // Prepare the data, the first level elements is the answer count by
        // the day
        _.each(dataRaw, function(dayValue, dayTimestamp, list) {
          var dayData = {};
          dayData.y = dayValue.answers.count;
          dayData.color = colors[0];
          dayData.drilldown = {};
          dayData.drilldown.name = dayValue.name_short;
          // The categories of the second level should be the category term's names
          dayData.drilldown.data = pickCountAndQuestionTitle(dayValue);
          data.push(dayData);
        });

        var chartNumberOfAnswers = new Highcharts.Chart({
          chart : {
            renderTo : 'vrc_sd_answer_posted_number_chart'
          },
          title : {
            text : 'Number of Answers Posted with Breakdown by Most Active Question <em>(last 30 days)</em>'
          },
          subtitle : {
            text : 'Click the column to see count breakdown by questions. Click again to view by days.'
          },
          xAxis : {
            categories : categories,
            labels : {
              allowPointSelect: true,
              rotation : -45,
              align : 'right',
              style : {
                fontSize : '8px',
                fontFamily : 'Verdana, sans-serif',
                color : '#666',
              }
            }
          },
          yAxis : {
            title : {
              text : 'Number of answers'
            }
          },
          plotOptions : {
            series : {
              cursor : 'pointer',
              point : {
                events : {
                  click : function() {
                    var drilldown = this.drilldown;
                    var options;
                    // drill down
                    if (drilldown) {
                      options = {
                        'type' : 'pie',
                        'name' : drilldown.name,
                        'categories' : drilldown.categories,
                        'data' : drilldown.data,
                        'color' : drilldown.color,
                      };
                    }
                    // restore
                    else {
                      options = {
                        'type' : 'column',
                        'name' : name,
                        'categories' : categories,
                        'data' : data,
                      };
                    }
                    setChartNumberOfAnswers(options);
                  }
                }
              },
              dataLabels : {
                enabled : true,
                color : colors[0],
                style : {
                  // fontWeight : 'bold'
                },
                formatter : function() {
                  if (this.series.options.type == 'pie') {
                    return this.point.name + ': <strong>' + this.y + '</strong><em>(' + Math.round(this.percentage) + '%)</em>';
                  }
                  else {
                    return this.y;
                  }
                  console.log(this);
                }
              }
            },
          },
          tooltip : {
            formatter : function() {
              var point = this.point;
              var s = this.x + ':<b>' + this.y + ' new answers</b><br/>';

              if (point.drilldown) {
                s += 'Click to view ' + point.category + ' by question';
              } else {
                s += 'Click to return to daily count';
              }
              return s;
            }
          },
          series : [ {
            type : 'column',
            name : name,
            data : data,
            color : 'white'
          } ],
          legend: {
            // Only one series, no need for this
            // enabled : false,
          },
          exporting : {
            enabled : false
          },
          credits : {
            enabled : false
          }
        })
      }

      if ($('#vrc_sd_answer_posted_number_chart').length > 0) {
        vrc_sd_draw_answer_posted_number_chart();
      }

      //------------------------------------------------------------------------
      //  HIGHCHART CHART - AVERAGE TIME FOR QUESTIONS TO GET FIRST ANSWER
      //------------------------------------------------------------------------
      function vrc_sd_draw_question_first_answer_time_chart() {
        var dataRaw = settings.vrc_highcharts.vrc_sd_question_first_answer_time.data;
        var chartAvgFirstAnswer = new Highcharts.Chart({
          chart : {
            renderTo : 'vrc_sd_question_first_answer_time_chart',
            type: 'line',
          },
          title : {
            text : 'Average time for question to get first answer'
          },
          subtitle : {
            text : 'Click the column to see count breakdown by categories. Click again to view by days.'
          },
          xAxis : {
            categories : _(dataRaw).pluck('name_short'),
            labels : {
              enabled : true,
              rotation : -45,
              align : 'right',
              style : {
                fontSize : '8px',
                fontFamily : 'Verdana, sans-serif',
                color : '#666',
              },
            }
          },
          yAxis : {
            title : {
              text : 'Time (days)'
            },
            labels: {
              formatter: function() {
                return jintervals(this.value, "{days}")
              }
            }
          },
          tooltip : {
            formatter : function() {
              var point = this.point;
              var t = jintervals(this.y, "{days} {hours}")
              var s = this.x + ':<b>' + t + '</b><br/>';
              return s;
            }
          },
          series : [ {
            type : 'line',
            name : 'Last 30 days',
            data : _(dataRaw).pluck('duration'),
          } ],
          legend: {
            // Only one series, no need for this
            // enabled : false,
          },
          exporting : {
            enabled : false
          },
          credits : {
            enabled : false
          }
        });
      }

      if ($('#vrc_sd_question_first_answer_time_chart').length > 0) {
        vrc_sd_draw_question_first_answer_time_chart();
      }

      //------------------------------------------------------------------------
      //  HIGHCHART CHART - AVERAGE TIME FOR QUESTIONS TO GET RESOLVED
      //------------------------------------------------------------------------
      function vrc_sd_draw_question_resolved_time_chart() {
        var dataRaw = settings.vrc_highcharts.vrc_sd_question_closing_time.data;
        var chartAvgQuestionClosing = new Highcharts.Chart({
          chart : {
            renderTo : 'vrc_sd_question_resolved_time_chart',
            type: 'line',
          },
          title : {
            text : 'Average time for question to get resolved'
          },
          subtitle : {
            text : 'Click the column to see count breakdown by categories. Click again to view by days.'
          },
          xAxis : {
            categories : _(dataRaw).pluck('name_short'),
            labels : {
              enabled : true,
              rotation : -45,
              align : 'right',
              style : {
                fontSize : '8px',
                fontFamily : 'Verdana, sans-serif',
                color : '#666',
              },
            }
          },
          yAxis : {
            title : {
              text : 'Time (days)'
            },
            labels: {
              formatter: function() {
                return jintervals(this.value, "{days}")
              }
            }
          },
          tooltip : {
            formatter : function() {
              var point = this.point;
              var t = jintervals(this.y, "{days} {hours}")
              var s = this.x + ':<b>' + t + '</b><br/>';
              return s;
            }
          },
          series : [ {
            type : 'line',
            name : 'Last 30 days',
            data : _(dataRaw).pluck('duration'),
          } ],
          legend: {
            // Only one series, no need for this
            // enabled : false,
          },
          exporting : {
            enabled : false
          },
          credits : {
            enabled : false
          }
        });
      }

      if ($('#vrc_sd_question_resolved_time_chart').length > 0) {
        vrc_sd_draw_question_resolved_time_chart();
      }

      //------------------------------------------------------------------------
      //  HIGHCHART CHART - CLOSING ANSWER AUTHOR RATIO
      //------------------------------------------------------------------------
      function vrc_sd_draw_closing_answer_author_ratio_chart() {
        var dataRaw = settings.vrc_highcharts.vrc_sd_closing_answer_author_ratio.data;

        var chartClosingAnswerAuthorRatio = new Highcharts.Chart({
          chart : {
            renderTo : 'vrc_sd_closing_answer_author_ratio_chart',
            type: 'line',
          },
          title : {
            text : 'Closing Answer Author Ratio <em>(Last 30 days)</em>'
          },
          subtitle : {
            // text : 'Last 30 days'
          },
          xAxis : {
            categories : _(dataRaw).pluck('name_short'),
            labels : {
              enabled : true,
              rotation : -45,
              align : 'right',
              style : {
                fontSize : '8px',
                fontFamily : 'Verdana, sans-serif',
                color : '#666',
              },
            }
          },
          yAxis : [{
            title : {
              text : 'User count'
            },
          }, {
            title : {
              text : 'Ratio (system users / normal users)'
            },
            opposite: true,
          }],
          tooltip : {
            formatter : function() {
              var text = '';
              switch (this.series.name) {
                case 'Normal Users':
                  text = this.y + ' normal users';
                  break;
                case 'System Users':
                  text = this.y + ' system users';
                  break;
                case 'Ratio':
                  text = 'Ratio: ' + this.y;
                  break;
                default:
                  text = this.y;
              }
              return text;
            }
          },
          series : [ {
            type : 'column',
            name : 'System Users',
            data : _(dataRaw).pluck('s_user_cnt'),
            yAxis : 1,
            color : '#E02A19',
          }, {
            type : 'column',
            name : 'Normal Users',
            data : _(dataRaw).pluck('n_user_cnt'),
            yAxis: 1,
            color : '#025945',
          }, {
            type : 'spline',
            name : 'Ratio',
            data : _(dataRaw).pluck('ratio'),
            yAxis: 0,
            color : '#636665',
          } ],
          legend: {
            // enabled : false,
          },
          exporting : {
            enabled : false
          },
          credits : {
            enabled : false
          }
        });
      }

      if ($('#vrc_sd_closing_answer_author_ratio_chart').length > 0) {
        vrc_sd_draw_closing_answer_author_ratio_chart();
      }

      //------------------------------------------------------------------------
      //  HIGHCHART CHART - QUESTION RESOLTUTION RATIO
      //------------------------------------------------------------------------
      function vrc_sd_draw_question_resolution_ratio_chart() {
        var dataRaw = settings.vrc_highcharts.vrc_sd_question_resolution_ratio.data;

        var chartClosingAnswerRatio = new Highcharts.Chart({
          chart : {
            renderTo : 'vrc_sd_question_resolution_ratio_chart',
            type: 'line',
          },
          title : {
            text : 'Closing Answer Author Ratio <em>(Last 30 days)</em>'
          },
          subtitle : {
            // text : 'Last 30 days'
          },
          xAxis : {
            categories : _(dataRaw).pluck('name_short'),
            labels : {
              enabled : true,
              rotation : -45,
              align : 'right',
              style : {
                fontSize : '8px',
                fontFamily : 'Verdana, sans-serif',
                color : '#666',
              },
            }
          },
          yAxis : [{
            title : {
              text : 'Questio Count'
            },
            labels: {
            }
          }, {
            title : {
              text : 'Ratio (Resolved Questions / Unresolved Questions)',
            },
            opposite: true,
          }],
          tooltip : {
            formatter : function() {
              var text = '';
              switch (this.series.name) {
                case 'Resolved Questions':
                  text = this.y + ' resolved questions';
                  break;
                case 'Unresolved Questions':
                  text = this.y + ' unresolved questions';
                  break;
                case 'Ratio':
                  text = 'Ratio: ' + this.y;
                  break;
                default:
                  text = this.y;
              }
              return text;
            }
          },
          series : [ {
            type : 'column',
            name : 'Resolved Questions',
            data : _(dataRaw).pluck('cnt_resolved'),
            yAxis: 1,
          }, {
            type : 'column',
            name : 'Unresolved Questions',
            data : _(dataRaw).pluck('cnt_unresolved'),
            yAxis: 1,
          }, {
            type : 'spline',
            name : 'Ratio',
            data : _(dataRaw).pluck('ratio'),
            yAxis: 0,
          } ],
          legend: {
            // enabled : false,
          },
          exporting : {
            enabled : false
          },
          credits : {
            enabled : false
          }
        });
      }

      if ($('#vrc_sd_question_resolution_ratio_chart').length > 0) {
        vrc_sd_draw_question_resolution_ratio_chart();
      }
    }
  };
})(jQuery);
