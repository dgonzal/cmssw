


<!DOCTYPE html>
<html lang="en" class="">
  <head prefix="og: http://ogp.me/ns# fb: http://ogp.me/ns/fb# object: http://ogp.me/ns/object# article: http://ogp.me/ns/article# profile: http://ogp.me/ns/profile#">
    <meta charset='utf-8'>
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta http-equiv="Content-Language" content="en">
    <meta name="viewport" content="width=1020">
    
    
    <title>cmssw/Validation_cff.py at 96ab5d7a9f93f13eaa1335c8a2fdcd2da8e96060 · cms-sw/cmssw · GitHub</title>
    <link rel="search" type="application/opensearchdescription+xml" href="/opensearch.xml" title="GitHub">
    <link rel="fluid-icon" href="https://github.com/fluidicon.png" title="GitHub">
    <link rel="apple-touch-icon" sizes="57x57" href="/apple-touch-icon-114.png">
    <link rel="apple-touch-icon" sizes="114x114" href="/apple-touch-icon-114.png">
    <link rel="apple-touch-icon" sizes="72x72" href="/apple-touch-icon-144.png">
    <link rel="apple-touch-icon" sizes="144x144" href="/apple-touch-icon-144.png">
    <meta property="fb:app_id" content="1401488693436528">

      <meta content="@github" name="twitter:site" /><meta content="summary" name="twitter:card" /><meta content="cms-sw/cmssw" name="twitter:title" /><meta content="cmssw - CMS Offline Software" name="twitter:description" /><meta content="https://avatars2.githubusercontent.com/u/3863500?v=3&amp;s=400" name="twitter:image:src" />
      <meta content="GitHub" property="og:site_name" /><meta content="object" property="og:type" /><meta content="https://avatars2.githubusercontent.com/u/3863500?v=3&amp;s=400" property="og:image" /><meta content="cms-sw/cmssw" property="og:title" /><meta content="https://github.com/cms-sw/cmssw" property="og:url" /><meta content="cmssw - CMS Offline Software" property="og:description" />
      <meta name="browser-stats-url" content="https://api.github.com/_private/browser/stats">
    <meta name="browser-errors-url" content="https://api.github.com/_private/browser/errors">
    <link rel="assets" href="https://assets-cdn.github.com/">
    
    <meta name="pjax-timeout" content="1000">
    

    <meta name="msapplication-TileImage" content="/windows-tile.png">
    <meta name="msapplication-TileColor" content="#ffffff">
    <meta name="selected-link" value="repo_source" data-pjax-transient>

        <meta name="google-analytics" content="UA-3769691-2">

    <meta content="collector.githubapp.com" name="octolytics-host" /><meta content="collector-cdn.github.com" name="octolytics-script-host" /><meta content="github" name="octolytics-app-id" /><meta content="BCB8441F:3D4B:1105C99E:55D48B8A" name="octolytics-dimension-request_id" />
    
    <meta content="Rails, view, blob#show" data-pjax-transient="true" name="analytics-event" />
    <meta class="js-ga-set" name="dimension1" content="Logged Out">
      <meta class="js-ga-set" name="dimension4" content="Current repo nav">
    <meta name="is-dotcom" content="true">
        <meta name="hostname" content="github.com">
    <meta name="user-login" content="">

      <link rel="icon" sizes="any" mask href="https://assets-cdn.github.com/pinned-octocat.svg">
      <meta name="theme-color" content="#4078c0">
      <link rel="icon" type="image/x-icon" href="https://assets-cdn.github.com/favicon.ico">

    <!-- </textarea> --><!-- '"` --><meta content="authenticity_token" name="csrf-param" />
<meta content="fxj95/OSrOLhofaUs4eh3hHW04FMxOETKkxBmcySkDjfU3sdfZ5GIOMaYtBqx+/KpUnkJUAGeH5lbcPCZep6Kw==" name="csrf-token" />
    

    <link crossorigin="anonymous" href="https://assets-cdn.github.com/assets/github/index-dbc2475c6d94e41c6ec8eaa1f8a81cd70dc0c76645c597c600d9d86d06a31789.css" media="all" rel="stylesheet" />
    <link crossorigin="anonymous" href="https://assets-cdn.github.com/assets/github2/index-1cab3ed64f98e531fbc3173c741f7d6fab31eed5a2087330402d3a966f26f7c6.css" media="all" rel="stylesheet" />
    
    


    <meta http-equiv="x-pjax-version" content="42038cd61e65f55d23f70722067e9e33">

      
  <meta name="description" content="cmssw - CMS Offline Software">
  <meta name="go-import" content="github.com/cms-sw/cmssw git https://github.com/cms-sw/cmssw.git">

  <meta content="3863500" name="octolytics-dimension-user_id" /><meta content="cms-sw" name="octolytics-dimension-user_login" /><meta content="10969551" name="octolytics-dimension-repository_id" /><meta content="cms-sw/cmssw" name="octolytics-dimension-repository_nwo" /><meta content="true" name="octolytics-dimension-repository_public" /><meta content="false" name="octolytics-dimension-repository_is_fork" /><meta content="10969551" name="octolytics-dimension-repository_network_root_id" /><meta content="cms-sw/cmssw" name="octolytics-dimension-repository_network_root_nwo" />
  <link href="https://github.com/cms-sw/cmssw/commits/96ab5d7a9f93f13eaa1335c8a2fdcd2da8e96060.atom" rel="alternate" title="Recent Commits to cmssw:96ab5d7a9f93f13eaa1335c8a2fdcd2da8e96060" type="application/atom+xml">

  </head>


  <body class="logged_out  env-production  vis-public page-blob">
    <a href="#start-of-content" tabindex="1" class="accessibility-aid js-skip-to-content">Skip to content</a>
    <div class="wrapper">
      
      
      



        
        <div class="header header-logged-out" role="banner">
  <div class="container clearfix">

    <a class="header-logo-wordmark" href="https://github.com/" data-ga-click="(Logged out) Header, go to homepage, icon:logo-wordmark">
      <span class="mega-octicon octicon-logo-github"></span>
    </a>

    <div class="header-actions" role="navigation">
        <a class="btn btn-primary" href="/join" data-ga-click="(Logged out) Header, clicked Sign up, text:sign-up">Sign up</a>
      <a class="btn" href="/login?return_to=%2Fcms-sw%2Fcmssw%2Fblob%2F96ab5d7a9f93f13eaa1335c8a2fdcd2da8e96060%2FFastSimulation%2FConfiguration%2Fpython%2FValidation_cff.py" data-ga-click="(Logged out) Header, clicked Sign in, text:sign-in">Sign in</a>
    </div>

    <div class="site-search repo-scope js-site-search" role="search">
      <!-- </textarea> --><!-- '"` --><form accept-charset="UTF-8" action="/cms-sw/cmssw/search" class="js-site-search-form" data-global-search-url="/search" data-repo-search-url="/cms-sw/cmssw/search" method="get"><div style="margin:0;padding:0;display:inline"><input name="utf8" type="hidden" value="&#x2713;" /></div>
  <label class="js-chromeless-input-container form-control">
    <div class="scope-badge">This repository</div>
    <input type="text"
      class="js-site-search-focus js-site-search-field is-clearable chromeless-input"
      data-hotkey="s"
      name="q"
      placeholder="Search"
      aria-label="Search this repository"
      data-global-scope-placeholder="Search GitHub"
      data-repo-scope-placeholder="Search"
      tabindex="1"
      autocapitalize="off">
  </label>
</form>
    </div>

      <ul class="header-nav left" role="navigation">
          <li class="header-nav-item">
            <a class="header-nav-link" href="/explore" data-ga-click="(Logged out) Header, go to explore, text:explore">Explore</a>
          </li>
          <li class="header-nav-item">
            <a class="header-nav-link" href="/features" data-ga-click="(Logged out) Header, go to features, text:features">Features</a>
          </li>
          <li class="header-nav-item">
            <a class="header-nav-link" href="https://enterprise.github.com/" data-ga-click="(Logged out) Header, go to enterprise, text:enterprise">Enterprise</a>
          </li>
          <li class="header-nav-item">
            <a class="header-nav-link" href="/pricing" data-ga-click="(Logged out) Header, go to pricing, text:pricing">Pricing</a>
          </li>
      </ul>

  </div>
</div>



      <div id="start-of-content" class="accessibility-aid"></div>
          <div class="site" itemscope itemtype="http://schema.org/WebPage">
    <div id="js-flash-container">
      
    </div>
    <div class="pagehead repohead instapaper_ignore readability-menu ">
      <div class="container">

        <div class="clearfix">
          
<ul class="pagehead-actions">

  <li>
      <a href="/login?return_to=%2Fcms-sw%2Fcmssw"
    class="btn btn-sm btn-with-count tooltipped tooltipped-n"
    aria-label="You must be signed in to watch a repository" rel="nofollow">
    <span class="octicon octicon-eye"></span>
    Watch
  </a>
  <a class="social-count" href="/cms-sw/cmssw/watchers">
    53
  </a>

  </li>

  <li>
      <a href="/login?return_to=%2Fcms-sw%2Fcmssw"
    class="btn btn-sm btn-with-count tooltipped tooltipped-n"
    aria-label="You must be signed in to star a repository" rel="nofollow">
    <span class="octicon octicon-star"></span>
    Star
  </a>

    <a class="social-count js-social-count" href="/cms-sw/cmssw/stargazers">
      256
    </a>

  </li>

    <li>
      <a href="/login?return_to=%2Fcms-sw%2Fcmssw"
        class="btn btn-sm btn-with-count tooltipped tooltipped-n"
        aria-label="You must be signed in to fork a repository" rel="nofollow">
        <span class="octicon octicon-repo-forked"></span>
        Fork
      </a>
      <a href="/cms-sw/cmssw/network" class="social-count">
        1,536
      </a>
    </li>
</ul>

          <h1 itemscope itemtype="http://data-vocabulary.org/Breadcrumb" class="entry-title public ">
            <span class="mega-octicon octicon-repo"></span>
            <span class="author"><a href="/cms-sw" class="url fn" itemprop="url" rel="author"><span itemprop="title">cms-sw</span></a></span><!--
         --><span class="path-divider">/</span><!--
         --><strong><a href="/cms-sw/cmssw" data-pjax="#js-repo-pjax-container">cmssw</a></strong>

            <span class="page-context-loader">
              <img alt="" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
            </span>

          </h1>
        </div>

      </div>
    </div>

      <div class="container">
        <div class="repository-with-sidebar repo-container new-discussion-timeline ">
          <div class="repository-sidebar clearfix">
              

<nav class="sunken-menu repo-nav js-repo-nav js-sidenav-container-pjax js-octicon-loaders"
     role="navigation"
     data-pjax="#js-repo-pjax-container"
     data-issue-count-url="/cms-sw/cmssw/issues/counts">
  <ul class="sunken-menu-group">
    <li class="tooltipped tooltipped-w" aria-label="Code">
      <a href="/cms-sw/cmssw" aria-label="Code" aria-selected="true" class="js-selected-navigation-item selected sunken-menu-item" data-hotkey="g c" data-selected-links="repo_source repo_downloads repo_commits repo_releases repo_tags repo_branches /cms-sw/cmssw">
        <span class="octicon octicon-code"></span> <span class="full-word">Code</span>
        <img alt="" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>    </li>

      <li class="tooltipped tooltipped-w" aria-label="Issues">
        <a href="/cms-sw/cmssw/issues" aria-label="Issues" class="js-selected-navigation-item sunken-menu-item" data-hotkey="g i" data-selected-links="repo_issues repo_labels repo_milestones /cms-sw/cmssw/issues">
          <span class="octicon octicon-issue-opened"></span> <span class="full-word">Issues</span>
          <span class="js-issue-replace-counter"></span>
          <img alt="" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>

    <li class="tooltipped tooltipped-w" aria-label="Pull requests">
      <a href="/cms-sw/cmssw/pulls" aria-label="Pull requests" class="js-selected-navigation-item sunken-menu-item" data-hotkey="g p" data-selected-links="repo_pulls /cms-sw/cmssw/pulls">
          <span class="octicon octicon-git-pull-request"></span> <span class="full-word">Pull requests</span>
          <span class="js-pull-replace-counter"></span>
          <img alt="" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>    </li>

  </ul>
  <div class="sunken-menu-separator"></div>
  <ul class="sunken-menu-group">

    <li class="tooltipped tooltipped-w" aria-label="Pulse">
      <a href="/cms-sw/cmssw/pulse" aria-label="Pulse" class="js-selected-navigation-item sunken-menu-item" data-selected-links="pulse /cms-sw/cmssw/pulse">
        <span class="octicon octicon-pulse"></span> <span class="full-word">Pulse</span>
        <img alt="" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>    </li>

    <li class="tooltipped tooltipped-w" aria-label="Graphs">
      <a href="/cms-sw/cmssw/graphs" aria-label="Graphs" class="js-selected-navigation-item sunken-menu-item" data-selected-links="repo_graphs repo_contributors /cms-sw/cmssw/graphs">
        <span class="octicon octicon-graph"></span> <span class="full-word">Graphs</span>
        <img alt="" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>    </li>
  </ul>


</nav>

                <div class="only-with-full-nav">
                    
<div class="js-clone-url clone-url open"
  data-protocol-type="http">
  <h3><span class="text-emphasized">HTTPS</span> clone URL</h3>
  <div class="input-group js-zeroclipboard-container">
    <input type="text" class="input-mini input-monospace js-url-field js-zeroclipboard-target"
           value="https://github.com/cms-sw/cmssw.git" readonly="readonly" aria-label="HTTPS clone URL">
    <span class="input-group-button">
      <button aria-label="Copy to clipboard" class="js-zeroclipboard btn btn-sm zeroclipboard-button tooltipped tooltipped-s" data-copied-hint="Copied!" type="button"><span class="octicon octicon-clippy"></span></button>
    </span>
  </div>
</div>

  
<div class="js-clone-url clone-url "
  data-protocol-type="subversion">
  <h3><span class="text-emphasized">Subversion</span> checkout URL</h3>
  <div class="input-group js-zeroclipboard-container">
    <input type="text" class="input-mini input-monospace js-url-field js-zeroclipboard-target"
           value="https://github.com/cms-sw/cmssw" readonly="readonly" aria-label="Subversion checkout URL">
    <span class="input-group-button">
      <button aria-label="Copy to clipboard" class="js-zeroclipboard btn btn-sm zeroclipboard-button tooltipped tooltipped-s" data-copied-hint="Copied!" type="button"><span class="octicon octicon-clippy"></span></button>
    </span>
  </div>
</div>



  <div class="clone-options">You can clone with
    <!-- </textarea> --><!-- '"` --><form accept-charset="UTF-8" action="/users/set_protocol?protocol_selector=http&amp;protocol_type=clone" class="inline-form js-clone-selector-form " data-form-nonce="5d1b93f1c97b19c7208e18bd9e892ae7d620f8ad" data-remote="true" method="post"><div style="margin:0;padding:0;display:inline"><input name="utf8" type="hidden" value="&#x2713;" /><input name="authenticity_token" type="hidden" value="G7FIf3P11K4iuKPXkTv8Y0X5JH2iY5P7wxSsFw42U7zEkSdI6NzsCWS/iov7jgiO9A6GuA2V4IZ9EK+jJh46xA==" /></div><button class="btn-link js-clone-selector" data-protocol="http" type="submit">HTTPS</button></form> or <!-- </textarea> --><!-- '"` --><form accept-charset="UTF-8" action="/users/set_protocol?protocol_selector=subversion&amp;protocol_type=clone" class="inline-form js-clone-selector-form " data-form-nonce="5d1b93f1c97b19c7208e18bd9e892ae7d620f8ad" data-remote="true" method="post"><div style="margin:0;padding:0;display:inline"><input name="utf8" type="hidden" value="&#x2713;" /><input name="authenticity_token" type="hidden" value="WOYjbqA7uQsJzu0Pw+csTAVihtDYg1TWk7J9Pq63Pby+N5KSkXzgoik6SgWn2714gKaE9NUYGFAohMUFsZvV+Q==" /></div><button class="btn-link js-clone-selector" data-protocol="subversion" type="submit">Subversion</button></form>.
    <a href="https://help.github.com/articles/which-remote-url-should-i-use" class="help tooltipped tooltipped-n" aria-label="Get help on which URL is right for you.">
      <span class="octicon octicon-question"></span>
    </a>
  </div>

                  <a href="/cms-sw/cmssw/archive/96ab5d7a9f93f13eaa1335c8a2fdcd2da8e96060.zip"
                     class="btn btn-sm sidebar-button"
                     aria-label="Download the contents of cms-sw/cmssw as a zip file"
                     title="Download the contents of cms-sw/cmssw as a zip file"
                     rel="nofollow">
                    <span class="octicon octicon-cloud-download"></span>
                    Download ZIP
                  </a>
                </div>
          </div>
          <div id="js-repo-pjax-container" class="repository-content context-loader-container" data-pjax-container>

            

<a href="/cms-sw/cmssw/blob/96ab5d7a9f93f13eaa1335c8a2fdcd2da8e96060/FastSimulation/Configuration/python/Validation_cff.py" class="hidden js-permalink-shortcut" data-hotkey="y">Permalink</a>

<!-- blob contrib key: blob_contributors:v21:6c97dfc5666bb862d9de6da1e044ac92 -->

  <div class="file-navigation js-zeroclipboard-container">
    
<div class="select-menu js-menu-container js-select-menu left">
  <span class="btn btn-sm select-menu-button js-menu-target css-truncate" data-hotkey="w"
    data-ref=""
    title=""
    role="button" aria-label="Switch branches or tags" tabindex="0" aria-haspopup="true">
    <i>Tree:</i>
    <span class="js-select-button css-truncate-target">96ab5d7a9f</span>
  </span>

  <div class="select-menu-modal-holder js-menu-content js-navigation-container" data-pjax aria-hidden="true">

    <div class="select-menu-modal">
      <div class="select-menu-header">
        <span class="select-menu-title">Switch branches/tags</span>
        <span class="octicon octicon-x js-menu-close" role="button" aria-label="Close"></span>
      </div>

      <div class="select-menu-filters">
        <div class="select-menu-text-filter">
          <input type="text" aria-label="Filter branches/tags" id="context-commitish-filter-field" class="js-filterable-field js-navigation-enable" placeholder="Filter branches/tags">
        </div>
        <div class="select-menu-tabs">
          <ul>
            <li class="select-menu-tab">
              <a href="#" data-tab-filter="branches" data-filter-placeholder="Filter branches/tags" class="js-select-menu-tab" role="tab">Branches</a>
            </li>
            <li class="select-menu-tab">
              <a href="#" data-tab-filter="tags" data-filter-placeholder="Find a tag…" class="js-select-menu-tab" role="tab">Tags</a>
            </li>
          </ul>
        </div>
      </div>

      <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket" data-tab-filter="branches" role="menu">

        <div data-filterable-for="context-commitish-filter-field" data-filterable-type="substring">


            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_4_1_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_4_1_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_4_1_X">
                CMSSW_4_1_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_4_2_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_4_2_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_4_2_X">
                CMSSW_4_2_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_4_4_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_4_4_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_4_4_X">
                CMSSW_4_4_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_5_2_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_5_2_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_5_2_X">
                CMSSW_5_2_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_5_3_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_5_3_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_5_3_X">
                CMSSW_5_3_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_6_1_X_SLHC/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_6_1_X_SLHC"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_6_1_X_SLHC">
                CMSSW_6_1_X_SLHC
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_6_2_0_SLHC12_patch/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_6_2_0_SLHC12_patch"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_6_2_0_SLHC12_patch">
                CMSSW_6_2_0_SLHC12_patch
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_6_2_0_SLHC15_fixTk/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_6_2_0_SLHC15_fixTk"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_6_2_0_SLHC15_fixTk">
                CMSSW_6_2_0_SLHC15_fixTk
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_6_2_SLHCDEV_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_6_2_SLHCDEV_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_6_2_SLHCDEV_X">
                CMSSW_6_2_SLHCDEV_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_6_2_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_6_2_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_6_2_X">
                CMSSW_6_2_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_6_2_X_SLHC/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_6_2_X_SLHC"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_6_2_X_SLHC">
                CMSSW_6_2_X_SLHC
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_0_0_pre/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_0_0_pre"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_0_0_pre">
                CMSSW_7_0_0_pre
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_0_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_0_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_0_X">
                CMSSW_7_0_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_0_XROOTD_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_0_XROOTD_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_0_XROOTD_X">
                CMSSW_7_0_XROOTD_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_1_4_patchX/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_1_4_patchX"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_1_4_patchX">
                CMSSW_7_1_4_patchX
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_1_9_patch/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_1_9_patch"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_1_9_patch">
                CMSSW_7_1_9_patch
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_1_CLANG_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_1_CLANG_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_1_CLANG_X">
                CMSSW_7_1_CLANG_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_1_DEVEL_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_1_DEVEL_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_1_DEVEL_X">
                CMSSW_7_1_DEVEL_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_1_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_1_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_1_X">
                CMSSW_7_1_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_2_0_patch/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_2_0_patch"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_2_0_patch">
                CMSSW_7_2_0_patch
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_2_0_pre3_conddb/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_2_0_pre3_conddb"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_2_0_pre3_conddb">
                CMSSW_7_2_0_pre3_conddb
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_2_BOOSTIO_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_2_BOOSTIO_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_2_BOOSTIO_X">
                CMSSW_7_2_BOOSTIO_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_2_CLANG_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_2_CLANG_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_2_CLANG_X">
                CMSSW_7_2_CLANG_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_2_DEVEL_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_2_DEVEL_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_2_DEVEL_X">
                CMSSW_7_2_DEVEL_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_2_GEANT10_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_2_GEANT10_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_2_GEANT10_X">
                CMSSW_7_2_GEANT10_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_2_ROOT6_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_2_ROOT6_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_2_ROOT6_X">
                CMSSW_7_2_ROOT6_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_2_THREADED_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_2_THREADED_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_2_THREADED_X">
                CMSSW_7_2_THREADED_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_2_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_2_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_2_X">
                CMSSW_7_2_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_3_CLANG_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_3_CLANG_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_3_CLANG_X">
                CMSSW_7_3_CLANG_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_3_DEVEL_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_3_DEVEL_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_3_DEVEL_X">
                CMSSW_7_3_DEVEL_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_3_GEANT10_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_3_GEANT10_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_3_GEANT10_X">
                CMSSW_7_3_GEANT10_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_3_ROOT6_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_3_ROOT6_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_3_ROOT6_X">
                CMSSW_7_3_ROOT6_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_3_THREADED_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_3_THREADED_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_3_THREADED_X">
                CMSSW_7_3_THREADED_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_3_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_3_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_3_X">
                CMSSW_7_3_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_4_0_pre/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_4_0_pre"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_4_0_pre">
                CMSSW_7_4_0_pre
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_4_1_patchX/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_4_1_patchX"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_4_1_patchX">
                CMSSW_7_4_1_patchX
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_4_2_patchX/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_4_2_patchX"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_4_2_patchX">
                CMSSW_7_4_2_patchX
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_4_CLANG_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_4_CLANG_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_4_CLANG_X">
                CMSSW_7_4_CLANG_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_4_DEVEL_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_4_DEVEL_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_4_DEVEL_X">
                CMSSW_7_4_DEVEL_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_4_GEANT10_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_4_GEANT10_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_4_GEANT10_X">
                CMSSW_7_4_GEANT10_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_4_ROOT5_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_4_ROOT5_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_4_ROOT5_X">
                CMSSW_7_4_ROOT5_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_4_ROOT6_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_4_ROOT6_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_4_ROOT6_X">
                CMSSW_7_4_ROOT6_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_4_THREADED_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_4_THREADED_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_4_THREADED_X">
                CMSSW_7_4_THREADED_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_4_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_4_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_4_X">
                CMSSW_7_4_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_5_ROOT5_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_5_ROOT5_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_5_ROOT5_X">
                CMSSW_7_5_ROOT5_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_5_ROOT64_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_5_ROOT64_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_5_ROOT64_X">
                CMSSW_7_5_ROOT64_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_5_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_5_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_5_X">
                CMSSW_7_5_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_6_ROOT64_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_6_ROOT64_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_6_ROOT64_X">
                CMSSW_7_6_ROOT64_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/CMSSW_7_6_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="CMSSW_7_6_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="CMSSW_7_6_X">
                CMSSW_7_6_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/externaldecay-update-on-top-off-5_3_14/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="externaldecay-update-on-top-off-5_3_14"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="externaldecay-update-on-top-off-5_3_14">
                externaldecay-update-on-top-off-5_3_14
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/imported-CVS-HEAD/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="imported-CVS-HEAD"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="imported-CVS-HEAD">
                imported-CVS-HEAD
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/ktf-patch-1/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="ktf-patch-1"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="ktf-patch-1">
                ktf-patch-1
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/ktf-patch-2/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="ktf-patch-2"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="ktf-patch-2">
                ktf-patch-2
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/revert-6751-NominalCollision2015-default-CMSSW_7_4_X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="revert-6751-NominalCollision2015-default-CMSSW_7_4_X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="revert-6751-NominalCollision2015-default-CMSSW_7_4_X">
                revert-6751-NominalCollision2015-default-CMSSW_7_4_X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/revert-6776-740p1_taus_switchConfDB/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="revert-6776-740p1_taus_switchConfDB"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="revert-6776-740p1_taus_switchConfDB">
                revert-6776-740p1_taus_switchConfDB
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/revert-6942-FSQDQM_74/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="revert-6942-FSQDQM_74"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="revert-6942-FSQDQM_74">
                revert-6942-FSQDQM_74
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/revert-7108-TriggerResultFilter_update_74x/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="revert-7108-TriggerResultFilter_update_74x"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="revert-7108-TriggerResultFilter_update_74x">
                revert-7108-TriggerResultFilter_update_74x
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/revert-7113-fixFillDescriptionInESRawToDigi/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="revert-7113-fixFillDescriptionInESRawToDigi"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="revert-7113-fixFillDescriptionInESRawToDigi">
                revert-7113-fixFillDescriptionInESRawToDigi
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/revert-7613-revert_to_conddb1/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="revert-7613-revert_to_conddb1"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="revert-7613-revert_to_conddb1">
                revert-7613-revert_to_conddb1
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/revert-7710-hcal_infinte_loop/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="revert-7710-hcal_infinte_loop"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="revert-7710-hcal_infinte_loop">
                revert-7710-hcal_infinte_loop
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/revert-8034-ExoValDev_74X_PR7_2/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="revert-8034-ExoValDev_74X_PR7_2"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="revert-8034-ExoValDev_74X_PR7_2">
                revert-8034-ExoValDev_74X_PR7_2
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/revert-8504-develop_Validation_PostProcessor/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="revert-8504-develop_Validation_PostProcessor"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="revert-8504-develop_Validation_PostProcessor">
                revert-8504-develop_Validation_PostProcessor
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/revert-9009-CMSSW_7_3_5_patch2/autoPseudoParabolic/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="revert-9009-CMSSW_7_3_5_patch2/autoPseudoParabolic"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="revert-9009-CMSSW_7_3_5_patch2/autoPseudoParabolic">
                revert-9009-CMSSW_7_3_5_patch2/autoPseudoParabolic
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/revert-9080-p5-addons/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="revert-9080-p5-addons"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="revert-9080-p5-addons">
                revert-9080-p5-addons
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/revert-9212-labels_v2/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="revert-9212-labels_v2"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="revert-9212-labels_v2">
                revert-9212-labels_v2
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/revert-9416-beamspot_kcanrebinFix_744p1/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="revert-9416-beamspot_kcanrebinFix_744p1"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="revert-9416-beamspot_kcanrebinFix_744p1">
                revert-9416-beamspot_kcanrebinFix_744p1
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/revert-9423-revert-9080-p5-addons/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="revert-9423-revert-9080-p5-addons"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="revert-9423-revert-9080-p5-addons">
                revert-9423-revert-9080-p5-addons
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/revert-9510-mergeDQMStore_74/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="revert-9510-mergeDQMStore_74"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="revert-9510-mergeDQMStore_74">
                revert-9510-mergeDQMStore_74
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/revert-9928-HLTTauValidationUpdate75X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="revert-9928-HLTTauValidationUpdate75X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="revert-9928-HLTTauValidationUpdate75X">
                revert-9928-HLTTauValidationUpdate75X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/revert-10138-unsch-RECO-together-miniAOD-fxConfl-CMSSW_7_4_X_2015-07-09-2300/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="revert-10138-unsch-RECO-together-miniAOD-fxConfl-CMSSW_7_4_X_2015-07-09-2300"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="revert-10138-unsch-RECO-together-miniAOD-fxConfl-CMSSW_7_4_X_2015-07-09-2300">
                revert-10138-unsch-RECO-together-miniAOD-fxConfl-CMSSW_7_4_X_2015-07-09-2300
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/revert-10154-75X_ExoLLRelVal/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="revert-10154-75X_ExoLLRelVal"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="revert-10154-75X_ExoLLRelVal">
                revert-10154-75X_ExoLLRelVal
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/revert-10276-HLTObjectMonitoring_74x/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="revert-10276-HLTObjectMonitoring_74x"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="revert-10276-HLTObjectMonitoring_74x">
                revert-10276-HLTObjectMonitoring_74x
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/revert-10277-HLTObjectMonitoring_75x/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="revert-10277-HLTObjectMonitoring_75x"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="revert-10277-HLTObjectMonitoring_75x">
                revert-10277-HLTObjectMonitoring_75x
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/revert-10278-HLTObjectMonitoring_76x/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="revert-10278-HLTObjectMonitoring_76x"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="revert-10278-HLTObjectMonitoring_76x">
                revert-10278-HLTObjectMonitoring_76x
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/revert-10559-cleaningMatrix76X/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="revert-10559-cleaningMatrix76X"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="revert-10559-cleaningMatrix76X">
                revert-10559-cleaningMatrix76X
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/test-commit/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="test-commit"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="test-commit">
                test-commit
              </span>
            </a>
            <a class="select-menu-item js-navigation-item js-navigation-open "
               href="/cms-sw/cmssw/blob/test-new-prs/FastSimulation/Configuration/python/Validation_cff.py"
               data-name="test-new-prs"
               data-skip-pjax="true"
               rel="nofollow">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <span class="select-menu-item-text css-truncate-target" title="test-new-prs">
                test-new-prs
              </span>
            </a>
        </div>

          <div class="select-menu-no-results">Nothing to show</div>
      </div>

      <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket" data-tab-filter="tags">
        <div data-filterable-for="context-commitish-filter-field" data-filterable-type="substring">


            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/untagged-215a6cfabb6564af9a73/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="untagged-215a6cfabb6564af9a73"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="untagged-215a6cfabb6564af9a73">untagged-215a6cfabb6564af9a73</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-19-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-19-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-19-1100">CMSSW_7_6_X_2015-08-19-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-18-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-18-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-18-2300">CMSSW_7_6_X_2015-08-18-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-18-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-18-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-18-1100">CMSSW_7_6_X_2015-08-18-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-17-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-17-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-17-2300">CMSSW_7_6_X_2015-08-17-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-17-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-17-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-17-1100">CMSSW_7_6_X_2015-08-17-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-16-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-16-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-16-2300">CMSSW_7_6_X_2015-08-16-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-16-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-16-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-16-1100">CMSSW_7_6_X_2015-08-16-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-15-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-15-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-15-2300">CMSSW_7_6_X_2015-08-15-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-15-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-15-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-15-1100">CMSSW_7_6_X_2015-08-15-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-14-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-14-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-14-2300">CMSSW_7_6_X_2015-08-14-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-14-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-14-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-14-1100">CMSSW_7_6_X_2015-08-14-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-13-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-13-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-13-2300">CMSSW_7_6_X_2015-08-13-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-13-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-13-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-13-1100">CMSSW_7_6_X_2015-08-13-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-12-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-12-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-12-2300">CMSSW_7_6_X_2015-08-12-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-12-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-12-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-12-1100">CMSSW_7_6_X_2015-08-12-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-11-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-11-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-11-2300">CMSSW_7_6_X_2015-08-11-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-11-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-11-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-11-1100">CMSSW_7_6_X_2015-08-11-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-10-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-10-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-10-2300">CMSSW_7_6_X_2015-08-10-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-10-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-10-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-10-1100">CMSSW_7_6_X_2015-08-10-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-09-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-09-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-09-1100">CMSSW_7_6_X_2015-08-09-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-08-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-08-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-08-2300">CMSSW_7_6_X_2015-08-08-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-08-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-08-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-08-1100">CMSSW_7_6_X_2015-08-08-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-07-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-07-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-07-2300">CMSSW_7_6_X_2015-08-07-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-07-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-07-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-07-1100">CMSSW_7_6_X_2015-08-07-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-06-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-06-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-06-2300">CMSSW_7_6_X_2015-08-06-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-06-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-06-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-06-1100">CMSSW_7_6_X_2015-08-06-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-05-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-05-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-05-2300">CMSSW_7_6_X_2015-08-05-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-05-1300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-05-1300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-05-1300">CMSSW_7_6_X_2015-08-05-1300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-05-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-05-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-05-1100">CMSSW_7_6_X_2015-08-05-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-04-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-04-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-04-2300">CMSSW_7_6_X_2015-08-04-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-04-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-04-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-04-1100">CMSSW_7_6_X_2015-08-04-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-03-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-03-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-03-2300">CMSSW_7_6_X_2015-08-03-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-03-1600/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-03-1600"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-03-1600">CMSSW_7_6_X_2015-08-03-1600</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-03-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-03-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-03-1100">CMSSW_7_6_X_2015-08-03-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-02-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-02-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-02-2300">CMSSW_7_6_X_2015-08-02-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-02-1000/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-02-1000"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-02-1000">CMSSW_7_6_X_2015-08-02-1000</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-01-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-01-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-01-2300">CMSSW_7_6_X_2015-08-01-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-08-01-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-08-01-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-08-01-1100">CMSSW_7_6_X_2015-08-01-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-31-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-31-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-31-2300">CMSSW_7_6_X_2015-07-31-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-31-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-31-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-31-1100">CMSSW_7_6_X_2015-07-31-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-30-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-30-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-30-2300">CMSSW_7_6_X_2015-07-30-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-30-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-30-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-30-1100">CMSSW_7_6_X_2015-07-30-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-29-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-29-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-29-2300">CMSSW_7_6_X_2015-07-29-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-29-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-29-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-29-1100">CMSSW_7_6_X_2015-07-29-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-28-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-28-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-28-2300">CMSSW_7_6_X_2015-07-28-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-28-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-28-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-28-1100">CMSSW_7_6_X_2015-07-28-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-27-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-27-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-27-2300">CMSSW_7_6_X_2015-07-27-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-27-1800/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-27-1800"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-27-1800">CMSSW_7_6_X_2015-07-27-1800</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-27-1300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-27-1300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-27-1300">CMSSW_7_6_X_2015-07-27-1300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-27-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-27-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-27-1100">CMSSW_7_6_X_2015-07-27-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-26-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-26-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-26-2300">CMSSW_7_6_X_2015-07-26-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-25-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-25-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-25-2300">CMSSW_7_6_X_2015-07-25-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-25-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-25-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-25-1100">CMSSW_7_6_X_2015-07-25-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-24-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-24-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-24-2300">CMSSW_7_6_X_2015-07-24-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-24-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-24-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-24-1100">CMSSW_7_6_X_2015-07-24-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-23-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-23-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-23-2300">CMSSW_7_6_X_2015-07-23-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-23-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-23-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-23-1100">CMSSW_7_6_X_2015-07-23-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-22-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-22-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-22-2300">CMSSW_7_6_X_2015-07-22-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-22-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-22-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-22-1100">CMSSW_7_6_X_2015-07-22-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-21-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-21-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-21-2300">CMSSW_7_6_X_2015-07-21-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-21-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-21-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-21-1100">CMSSW_7_6_X_2015-07-21-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-21-1000/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-21-1000"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-21-1000">CMSSW_7_6_X_2015-07-21-1000</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-20-1800/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-20-1800"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-20-1800">CMSSW_7_6_X_2015-07-20-1800</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-20-1600/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-20-1600"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-20-1600">CMSSW_7_6_X_2015-07-20-1600</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-20-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-20-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-20-1100">CMSSW_7_6_X_2015-07-20-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-20-0800/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-20-0800"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-20-0800">CMSSW_7_6_X_2015-07-20-0800</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-19-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-19-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-19-2300">CMSSW_7_6_X_2015-07-19-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-19-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-19-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-19-1100">CMSSW_7_6_X_2015-07-19-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-18-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-18-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-18-2300">CMSSW_7_6_X_2015-07-18-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-18-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-18-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-18-1100">CMSSW_7_6_X_2015-07-18-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-17-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-17-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-17-2300">CMSSW_7_6_X_2015-07-17-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-17-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-17-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-17-1100">CMSSW_7_6_X_2015-07-17-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-16-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-16-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-16-2300">CMSSW_7_6_X_2015-07-16-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-16-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-16-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-16-1100">CMSSW_7_6_X_2015-07-16-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-15-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-15-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-15-2300">CMSSW_7_6_X_2015-07-15-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-15-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-15-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-15-1100">CMSSW_7_6_X_2015-07-15-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-14-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-14-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-14-2300">CMSSW_7_6_X_2015-07-14-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-14-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-14-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-14-1100">CMSSW_7_6_X_2015-07-14-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-13-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-13-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-13-2300">CMSSW_7_6_X_2015-07-13-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-13-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-13-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-13-1100">CMSSW_7_6_X_2015-07-13-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_X_2015-07-12-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_X_2015-07-12-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_X_2015-07-12-2300">CMSSW_7_6_X_2015-07-12-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_THREADED_X_2015-08-19-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_THREADED_X_2015-08-19-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_THREADED_X_2015-08-19-1100">CMSSW_7_6_THREADED_X_2015-08-19-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_THREADED_X_2015-08-18-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_THREADED_X_2015-08-18-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_THREADED_X_2015-08-18-2300">CMSSW_7_6_THREADED_X_2015-08-18-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_THREADED_X_2015-08-18-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_THREADED_X_2015-08-18-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_THREADED_X_2015-08-18-1100">CMSSW_7_6_THREADED_X_2015-08-18-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_THREADED_X_2015-08-17-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_THREADED_X_2015-08-17-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_THREADED_X_2015-08-17-2300">CMSSW_7_6_THREADED_X_2015-08-17-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_THREADED_X_2015-08-17-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_THREADED_X_2015-08-17-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_THREADED_X_2015-08-17-1100">CMSSW_7_6_THREADED_X_2015-08-17-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_THREADED_X_2015-08-16-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_THREADED_X_2015-08-16-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_THREADED_X_2015-08-16-2300">CMSSW_7_6_THREADED_X_2015-08-16-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_THREADED_X_2015-08-16-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_THREADED_X_2015-08-16-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_THREADED_X_2015-08-16-1100">CMSSW_7_6_THREADED_X_2015-08-16-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_THREADED_X_2015-08-15-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_THREADED_X_2015-08-15-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_THREADED_X_2015-08-15-2300">CMSSW_7_6_THREADED_X_2015-08-15-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_THREADED_X_2015-08-15-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_THREADED_X_2015-08-15-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_THREADED_X_2015-08-15-1100">CMSSW_7_6_THREADED_X_2015-08-15-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_THREADED_X_2015-08-14-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_THREADED_X_2015-08-14-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_THREADED_X_2015-08-14-2300">CMSSW_7_6_THREADED_X_2015-08-14-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_THREADED_X_2015-08-14-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_THREADED_X_2015-08-14-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_THREADED_X_2015-08-14-1100">CMSSW_7_6_THREADED_X_2015-08-14-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_THREADED_X_2015-08-13-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_THREADED_X_2015-08-13-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_THREADED_X_2015-08-13-2300">CMSSW_7_6_THREADED_X_2015-08-13-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_THREADED_X_2015-08-13-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_THREADED_X_2015-08-13-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_THREADED_X_2015-08-13-1100">CMSSW_7_6_THREADED_X_2015-08-13-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_THREADED_X_2015-08-12-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_THREADED_X_2015-08-12-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_THREADED_X_2015-08-12-2300">CMSSW_7_6_THREADED_X_2015-08-12-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_THREADED_X_2015-08-12-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_THREADED_X_2015-08-12-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_THREADED_X_2015-08-12-1100">CMSSW_7_6_THREADED_X_2015-08-12-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_THREADED_X_2015-08-11-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_THREADED_X_2015-08-11-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_THREADED_X_2015-08-11-2300">CMSSW_7_6_THREADED_X_2015-08-11-2300</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_THREADED_X_2015-08-11-1100/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_THREADED_X_2015-08-11-1100"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_THREADED_X_2015-08-11-1100">CMSSW_7_6_THREADED_X_2015-08-11-1100</a>
            </div>
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/cms-sw/cmssw/tree/CMSSW_7_6_THREADED_X_2015-08-10-2300/FastSimulation/Configuration/python/Validation_cff.py"
                 data-name="CMSSW_7_6_THREADED_X_2015-08-10-2300"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="CMSSW_7_6_THREADED_X_2015-08-10-2300">CMSSW_7_6_THREADED_X_2015-08-10-2300</a>
            </div>
        </div>

        <div class="select-menu-no-results">Nothing to show</div>
      </div>

    </div>
  </div>
</div>

    <div class="btn-group right">
      <a href="/cms-sw/cmssw/find/96ab5d7a9f93f13eaa1335c8a2fdcd2da8e96060"
            class="js-show-file-finder btn btn-sm empty-icon tooltipped tooltipped-nw"
            data-pjax
            data-hotkey="t"
            aria-label="Quickly jump between files">
        <span class="octicon octicon-list-unordered"></span>
      </a>
      <button aria-label="Copy file path to clipboard" class="js-zeroclipboard btn btn-sm zeroclipboard-button tooltipped tooltipped-s" data-copied-hint="Copied!" type="button"><span class="octicon octicon-clippy"></span></button>
    </div>

    <div class="breadcrumb js-zeroclipboard-target">
      <span class="repo-root js-repo-root"><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/cms-sw/cmssw/tree/96ab5d7a9f93f13eaa1335c8a2fdcd2da8e96060" class="" data-branch="96ab5d7a9f93f13eaa1335c8a2fdcd2da8e96060" data-pjax="true" itemscope="url" rel="nofollow"><span itemprop="title">cmssw</span></a></span></span><span class="separator">/</span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/cms-sw/cmssw/tree/96ab5d7a9f93f13eaa1335c8a2fdcd2da8e96060/FastSimulation" class="" data-branch="96ab5d7a9f93f13eaa1335c8a2fdcd2da8e96060" data-pjax="true" itemscope="url" rel="nofollow"><span itemprop="title">FastSimulation</span></a></span><span class="separator">/</span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/cms-sw/cmssw/tree/96ab5d7a9f93f13eaa1335c8a2fdcd2da8e96060/FastSimulation/Configuration" class="" data-branch="96ab5d7a9f93f13eaa1335c8a2fdcd2da8e96060" data-pjax="true" itemscope="url" rel="nofollow"><span itemprop="title">Configuration</span></a></span><span class="separator">/</span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/cms-sw/cmssw/tree/96ab5d7a9f93f13eaa1335c8a2fdcd2da8e96060/FastSimulation/Configuration/python" class="" data-branch="96ab5d7a9f93f13eaa1335c8a2fdcd2da8e96060" data-pjax="true" itemscope="url" rel="nofollow"><span itemprop="title">python</span></a></span><span class="separator">/</span><strong class="final-path">Validation_cff.py</strong>
    </div>
  </div>


  <div class="commit file-history-tease">
    <div class="file-history-tease-header">
        <img alt="@lveldere" class="avatar" height="24" src="https://avatars2.githubusercontent.com/u/5065551?v=3&amp;s=48" width="24" />
        <span class="author"><a href="/lveldere" rel="contributor">lveldere</a></span>
        <time datetime="2015-01-10T13:16:56Z" is="relative-time">Jan 10, 2015</time>
        <div class="commit-title">
            <a href="/cms-sw/cmssw/commit/4b5eef056e648ed42aefa87aab71f6151bc75c2f" class="message" data-pjax="true" title="fastsim: add tau validation sequence to fastsim validation sequence">fastsim: add tau validation sequence to fastsim validation sequence</a>
        </div>
    </div>

    <div class="participation">
      <p class="quickstat">
        <a href="#blob_contributors_box" rel="facebox">
          <strong>5</strong>
           contributors
        </a>
      </p>
          <a class="avatar-link tooltipped tooltipped-s" aria-label="webermat" href="/cms-sw/cmssw/commits/96ab5d7a9f93f13eaa1335c8a2fdcd2da8e96060/FastSimulation/Configuration/python/Validation_cff.py?author=webermat"><img alt="@webermat" class="avatar" height="20" src="https://avatars3.githubusercontent.com/u/4601310?v=3&amp;s=40" width="20" /> </a>
    <a class="avatar-link tooltipped tooltipped-s" aria-label="lveldere" href="/cms-sw/cmssw/commits/96ab5d7a9f93f13eaa1335c8a2fdcd2da8e96060/FastSimulation/Configuration/python/Validation_cff.py?author=lveldere"><img alt="@lveldere" class="avatar" height="20" src="https://avatars0.githubusercontent.com/u/5065551?v=3&amp;s=40" width="20" /> </a>
    <a class="avatar-link tooltipped tooltipped-s" aria-label="ktf" href="/cms-sw/cmssw/commits/96ab5d7a9f93f13eaa1335c8a2fdcd2da8e96060/FastSimulation/Configuration/python/Validation_cff.py?author=ktf"><img alt="@ktf" class="avatar" height="20" src="https://avatars0.githubusercontent.com/u/10544?v=3&amp;s=40" width="20" /> </a>
    <a class="avatar-link tooltipped tooltipped-s" aria-label="deguio" href="/cms-sw/cmssw/commits/96ab5d7a9f93f13eaa1335c8a2fdcd2da8e96060/FastSimulation/Configuration/python/Validation_cff.py?author=deguio"><img alt="@deguio" class="avatar" height="20" src="https://avatars1.githubusercontent.com/u/3207679?v=3&amp;s=40" width="20" /> </a>
    <a class="avatar-link tooltipped tooltipped-s" aria-label="davidlange6" href="/cms-sw/cmssw/commits/96ab5d7a9f93f13eaa1335c8a2fdcd2da8e96060/FastSimulation/Configuration/python/Validation_cff.py?author=davidlange6"><img alt="@davidlange6" class="avatar" height="20" src="https://avatars1.githubusercontent.com/u/5042883?v=3&amp;s=40" width="20" /> </a>


    </div>
    <div id="blob_contributors_box" style="display:none">
      <h2 class="facebox-header">Users who have contributed to this file</h2>
      <ul class="facebox-user-list">
          <li class="facebox-user-list-item">
            <img alt="@webermat" height="24" src="https://avatars1.githubusercontent.com/u/4601310?v=3&amp;s=48" width="24" />
            <a href="/webermat">webermat</a>
          </li>
          <li class="facebox-user-list-item">
            <img alt="@lveldere" height="24" src="https://avatars2.githubusercontent.com/u/5065551?v=3&amp;s=48" width="24" />
            <a href="/lveldere">lveldere</a>
          </li>
          <li class="facebox-user-list-item">
            <img alt="@ktf" height="24" src="https://avatars2.githubusercontent.com/u/10544?v=3&amp;s=48" width="24" />
            <a href="/ktf">ktf</a>
          </li>
          <li class="facebox-user-list-item">
            <img alt="@deguio" height="24" src="https://avatars3.githubusercontent.com/u/3207679?v=3&amp;s=48" width="24" />
            <a href="/deguio">deguio</a>
          </li>
          <li class="facebox-user-list-item">
            <img alt="@davidlange6" height="24" src="https://avatars3.githubusercontent.com/u/5042883?v=3&amp;s=48" width="24" />
            <a href="/davidlange6">davidlange6</a>
          </li>
      </ul>
    </div>
  </div>

<div class="file">
  <div class="file-header">
    <div class="file-actions">

      <div class="btn-group">
        <a href="/cms-sw/cmssw/raw/96ab5d7a9f93f13eaa1335c8a2fdcd2da8e96060/FastSimulation/Configuration/python/Validation_cff.py" class="btn btn-sm " id="raw-url">Raw</a>
          <a href="/cms-sw/cmssw/blame/96ab5d7a9f93f13eaa1335c8a2fdcd2da8e96060/FastSimulation/Configuration/python/Validation_cff.py" class="btn btn-sm js-update-url-with-hash">Blame</a>
        <a href="/cms-sw/cmssw/commits/96ab5d7a9f93f13eaa1335c8a2fdcd2da8e96060/FastSimulation/Configuration/python/Validation_cff.py" class="btn btn-sm " rel="nofollow">History</a>
      </div>


          <button type="button" class="octicon-btn disabled tooltipped tooltipped-n" aria-label="You must be signed in to make or propose changes">
            <span class="octicon octicon-pencil"></span>
          </button>

        <button type="button" class="octicon-btn octicon-btn-danger disabled tooltipped tooltipped-n" aria-label="You must be signed in to make or propose changes">
          <span class="octicon octicon-trashcan"></span>
        </button>
    </div>

    <div class="file-info">
        15 lines (13 sloc)
        <span class="file-info-divider"></span>
      0.883 kB
    </div>
  </div>
  

  <div class="blob-wrapper data type-python">
      <table class="highlight tab-size js-file-line-container" data-tab-size="8">
      <tr>
        <td id="L1" class="blob-num js-line-number" data-line-number="1"></td>
        <td id="LC1" class="blob-code blob-code-inner js-file-line"><span class="pl-k">import</span> FWCore.ParameterSet.Config <span class="pl-k">as</span> cms</td>
      </tr>
      <tr>
        <td id="L2" class="blob-num js-line-number" data-line-number="2"></td>
        <td id="LC2" class="blob-code blob-code-inner js-file-line"><span class="pl-k">from</span> Validation.EventGenerator.BasicGenValidation_cff <span class="pl-k">import</span> <span class="pl-k">*</span></td>
      </tr>
      <tr>
        <td id="L3" class="blob-num js-line-number" data-line-number="3"></td>
        <td id="LC3" class="blob-code blob-code-inner js-file-line"><span class="pl-k">from</span> FastSimulation.Validation.globalValidation_cff <span class="pl-k">import</span> <span class="pl-k">*</span></td>
      </tr>
      <tr>
        <td id="L4" class="blob-num js-line-number" data-line-number="4"></td>
        <td id="LC4" class="blob-code blob-code-inner js-file-line"><span class="pl-k">from</span> HLTriggerOffline.Common.HLTValidation_cff <span class="pl-k">import</span> <span class="pl-k">*</span></td>
      </tr>
      <tr>
        <td id="L5" class="blob-num js-line-number" data-line-number="5"></td>
        <td id="LC5" class="blob-code blob-code-inner js-file-line"><span class="pl-k">from</span> DQM.Physics.DQMPhysics_cff <span class="pl-k">import</span> <span class="pl-k">*</span></td>
      </tr>
      <tr>
        <td id="L6" class="blob-num js-line-number" data-line-number="6"></td>
        <td id="LC6" class="blob-code blob-code-inner js-file-line"><span class="pl-k">from</span> Validation.RecoMET.METRelValForDQM_cff <span class="pl-k">import</span> metPreValidSeq</td>
      </tr>
      <tr>
        <td id="L7" class="blob-num js-line-number" data-line-number="7"></td>
        <td id="LC7" class="blob-code blob-code-inner js-file-line"><span class="pl-k">from</span> Validation.RecoJets.JetValidation_cff <span class="pl-k">import</span> jetPreValidSeq </td>
      </tr>
      <tr>
        <td id="L8" class="blob-num js-line-number" data-line-number="8"></td>
        <td id="LC8" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="L9" class="blob-num js-line-number" data-line-number="9"></td>
        <td id="LC9" class="blob-code blob-code-inner js-file-line">prevalidation <span class="pl-k">=</span> cms.Sequence(globalPrevalidation<span class="pl-k">+</span>hltassociation_fastsim<span class="pl-k">+</span>metPreValidSeq<span class="pl-k">+</span>jetPreValidSeq)</td>
      </tr>
      <tr>
        <td id="L10" class="blob-num js-line-number" data-line-number="10"></td>
        <td id="LC10" class="blob-code blob-code-inner js-file-line">prevalidation_preprod <span class="pl-k">=</span> cms.Sequence(globalPrevalidation)</td>
      </tr>
      <tr>
        <td id="L11" class="blob-num js-line-number" data-line-number="11"></td>
        <td id="LC11" class="blob-code blob-code-inner js-file-line">prevalidation_prod <span class="pl-k">=</span> cms.Sequence(globalPrevalidation)</td>
      </tr>
      <tr>
        <td id="L12" class="blob-num js-line-number" data-line-number="12"></td>
        <td id="LC12" class="blob-code blob-code-inner js-file-line">validation <span class="pl-k">=</span> cms.Sequence(basicGenTest_seq<span class="pl-k">+</span>globalValidation<span class="pl-k">+</span>hltvalidation_fastsim<span class="pl-k">+</span>dqmPhysics) </td>
      </tr>
      <tr>
        <td id="L13" class="blob-num js-line-number" data-line-number="13"></td>
        <td id="LC13" class="blob-code blob-code-inner js-file-line">validation_preprod <span class="pl-k">=</span> cms.Sequence(basicGenTest_seq<span class="pl-k">+</span>globalValidation_preprod<span class="pl-k">+</span>hltvalidation_preprod_fastsim) </td>
      </tr>
      <tr>
        <td id="L14" class="blob-num js-line-number" data-line-number="14"></td>
        <td id="LC14" class="blob-code blob-code-inner js-file-line">validation_prod <span class="pl-k">=</span> cms.Sequence(basicGenTest_seq<span class="pl-k">+</span>hltvalidation_prod) </td>
      </tr>
</table>

  </div>

</div>

<a href="#jump-to-line" rel="facebox[.linejump]" data-hotkey="l" style="display:none">Jump to Line</a>
<div id="jump-to-line" style="display:none">
  <!-- </textarea> --><!-- '"` --><form accept-charset="UTF-8" action="" class="js-jump-to-line-form" method="get"><div style="margin:0;padding:0;display:inline"><input name="utf8" type="hidden" value="&#x2713;" /></div>
    <input class="linejump-input js-jump-to-line-field" type="text" placeholder="Jump to line&hellip;" aria-label="Jump to line" autofocus>
    <button type="submit" class="btn">Go</button>
</form></div>

          </div>
        </div>
        <div class="modal-backdrop"></div>
      </div>
  </div>


    </div><!-- /.wrapper -->

      <div class="container">
  <div class="site-footer" role="contentinfo">
    <ul class="site-footer-links right">
        <li><a href="https://status.github.com/" data-ga-click="Footer, go to status, text:status">Status</a></li>
      <li><a href="https://developer.github.com" data-ga-click="Footer, go to api, text:api">API</a></li>
      <li><a href="https://training.github.com" data-ga-click="Footer, go to training, text:training">Training</a></li>
      <li><a href="https://shop.github.com" data-ga-click="Footer, go to shop, text:shop">Shop</a></li>
        <li><a href="https://github.com/blog" data-ga-click="Footer, go to blog, text:blog">Blog</a></li>
        <li><a href="https://github.com/about" data-ga-click="Footer, go to about, text:about">About</a></li>
        <li><a href="https://github.com/pricing" data-ga-click="Footer, go to pricing, text:pricing">Pricing</a></li>

    </ul>

    <a href="https://github.com" aria-label="Homepage">
      <span class="mega-octicon octicon-mark-github" title="GitHub"></span>
</a>
    <ul class="site-footer-links">
      <li>&copy; 2015 <span title="0.14520s from github-fe120-cp1-prd.iad.github.net">GitHub</span>, Inc.</li>
        <li><a href="https://github.com/site/terms" data-ga-click="Footer, go to terms, text:terms">Terms</a></li>
        <li><a href="https://github.com/site/privacy" data-ga-click="Footer, go to privacy, text:privacy">Privacy</a></li>
        <li><a href="https://github.com/security" data-ga-click="Footer, go to security, text:security">Security</a></li>
        <li><a href="https://github.com/contact" data-ga-click="Footer, go to contact, text:contact">Contact</a></li>
        <li><a href="https://help.github.com" data-ga-click="Footer, go to help, text:help">Help</a></li>
    </ul>
  </div>
</div>


    <div class="fullscreen-overlay js-fullscreen-overlay" id="fullscreen_overlay">
  <div class="fullscreen-container js-suggester-container">
    <div class="textarea-wrap">
      <textarea name="fullscreen-contents" id="fullscreen-contents" class="fullscreen-contents js-fullscreen-contents" placeholder="" aria-label=""></textarea>
      <div class="suggester-container">
        <div class="suggester fullscreen-suggester js-suggester js-navigation-container"></div>
      </div>
    </div>
  </div>
  <div class="fullscreen-sidebar">
    <a href="#" class="exit-fullscreen js-exit-fullscreen tooltipped tooltipped-w" aria-label="Exit Zen Mode">
      <span class="mega-octicon octicon-screen-normal"></span>
    </a>
    <a href="#" class="theme-switcher js-theme-switcher tooltipped tooltipped-w"
      aria-label="Switch themes">
      <span class="octicon octicon-color-mode"></span>
    </a>
  </div>
</div>



    
    

    <div id="ajax-error-message" class="flash flash-error">
      <span class="octicon octicon-alert"></span>
      <a href="#" class="octicon octicon-x flash-close js-ajax-error-dismiss" aria-label="Dismiss error"></a>
      Something went wrong with that request. Please try again.
    </div>


      <script crossorigin="anonymous" src="https://assets-cdn.github.com/assets/frameworks-d57b85eb0208f46172d97d4746c78b19441b324803d3cc53d37e5a405f584b6d.js"></script>
      <script async="async" crossorigin="anonymous" src="https://assets-cdn.github.com/assets/github/index-6a674366e1a2a508a2f63b74540b455873cc9feaa76663b11b7c47114c7b2c7b.js"></script>
      
      
    <div class="js-stale-session-flash stale-session-flash flash flash-warn flash-banner hidden">
      <span class="octicon octicon-alert"></span>
      <span class="signed-in-tab-flash">You signed in with another tab or window. <a href="">Reload</a> to refresh your session.</span>
      <span class="signed-out-tab-flash">You signed out in another tab or window. <a href="">Reload</a> to refresh your session.</span>
    </div>
  </body>
</html>

